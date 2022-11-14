import datetime
import pandas as pd
from urllib3 import Retry
from requests.adapters import HTTPAdapter
from tools.zytools.tools.anomaly import anomaly
from tools.zytools.tools.detailedview import detailedview
from tools.zytools.tools.roster import roster
from tools.zytools.tools.quickanalysis import quick_analysis
from tools.zytools.tools.submission import Submission
from tools.zytools.tools.stylechecker import stylechecker
from tools.zytools.tools.detailedview import detailedview
import requests
import zipfile
import io
from tools.zytools.tools import incdev
import os
import csv
from datetime import datetime
from concurrent.futures import ThreadPoolExecutor, as_completed

##############################
#       Helper Functions     #
##############################
class Not200Exception(Exception):
    """Raise this custom exception if we receive a "valid" response from the server, but no data is present"""
    pass

def get_valid_datetime(timestamp):
    t = timestamp
    for fmt in ('%m/%d/%Y %H:%M:%S', '%Y-%m-%d %H:%M:%S', '%m/%d/%Y %H:%M:%S','%m/%d/%y %H:%M'):
        try:
            return datetime.strptime(t, fmt)
        except ValueError:
            pass
    raise ValueError('Cannot recognize datetime format: ' + t)

def download_code_helper(url):
    # Define our retry strategy for all HTTP requests
    retry_strategy = Retry(
        total=3,
        backoff_factor=1,
        status_forcelist=[429, 500, 502, 503, 504]
    )
    adapter = requests.adapters.HTTPAdapter(max_retries=retry_strategy)
    session = requests.Session()
    session.mount('https://', adapter)
    session.mount('http://', adapter)
    file_name = url.split('/')[-1].strip('.zip')
    path = 'tools/zytools/downloads/' + file_name +'.cpp'
    if not os.path.isfile(path):
        try:
            response = session.get(url)
            if response.status_code > 200 and response.status_code < 300:
                raise Not200Exception
            zfile = zipfile.ZipFile(io.BytesIO(response.content))
            filenames = zfile.namelist()
            content = zfile.open(filenames[0], 'r').read()
            result = content.decode('utf-8')
            with open(path, 'w', encoding="utf-8") as file:
                file.write(result)
            return (url, result)
        except Not200Exception:
            return (url, "Successfully received a response, but not data was received")
        except ConnectionError:
            return (url, "Max retries met, cannot retrieve student code submission")
    else:
        with open(path, 'r') as file:
            result = file.read()
        return (url, result)

def download_code(logfile):
    urls = logfile.zip_location.to_list()
    student_code = []
    threads = []
    print("Downloading student code...")
    with ThreadPoolExecutor() as executor:
        for url in urls:
            threads.append(executor.submit(download_code_helper, url))
        student_code = []
        i = 0
        for task in as_completed(threads):
            student_code.append(task.result())
    df = pd.DataFrame(student_code, columns = ['zip_location', 'student_code'])
    logfile = pd.merge(left=logfile, right=df, on=['zip_location'])
    return logfile

def get_selected_labs(logfile):
    lab_ids = logfile.content_section.unique()
    # Select the labs you want a roster for 
    print('Select the indexes you want a roster for seperated by a space: (Ex: 1 or 1 2 3 or 2 3)')
    labs_list = []
    i = 0
    print(i,'  select all labs')
    i += 1
    for lab_id in lab_ids:
        print(i,' ', lab_id, logfile.query('content_section =='+ str(lab_id))['caption'].iloc[0])
        labs_list.append(lab_id)
        i += 1
    selected_options = input()
    selected_labs = []
    if selected_options.split()[0] == '0':
        for lab in labs_list:
            selected_labs.append(lab)
    else:
        selected_lab_index = selected_options.split()
        for selected_lab in selected_lab_index:
            selected_labs.append(labs_list[int(selected_lab)-1])
    return selected_labs

def write_output_to_csv(final_roster):
    # # Writing the output to the csv file 
    now = str(datetime.now())
    csv_columns = []
    for id in final_roster:
        for column in final_roster[id]:
            # print(summary_roster[id])
            if column not in csv_columns:
                csv_columns.append(column)          
    try:
        csv_file = 'output/roster'+ now + '.csv'
        with open(csv_file, 'w') as f1:
            writer = csv.DictWriter(f1, fieldnames=csv_columns)
            writer.writeheader()
            for user_id in final_roster.keys():
                writer.writerow(final_roster[user_id])
    except IOError:
        print('IO Error')

def create_data_structure(logfile):
    data = {}
    for row in logfile.itertuples():
        if row.user_id not in data:
            data[int(row.user_id)] = {}
        if row.content_section not in data[row.user_id]:
            data[row.user_id][row.content_section] = []
        # url, result = get_code(row.zip_location)
        sub = Submission(
            student_id = row.user_id,
            crid = row.content_resource_id,
            caption = row.caption,
            first_name = row.first_name,
            last_name = row.last_name,
            email = row.email,
            zip_location = row.zip_location,
            submission = row.submission,
            max_score = row.score,
            lab_id = row.content_section,
            submission_id = row.zip_location.split('/')[-1].strip('.zip'),
            type = row.submission,
            code = row.student_code,
            sub_time = get_valid_datetime(row.date_submitted),
            anomaly_dict=None
        )
        data[row.user_id][row.content_section].append(sub)
    return data


##############################
#           Control          #
##############################
if __name__ == '__main__':
    # Read File into a pandas dataframe
    # file_path = input('Enter path to the file including file name: ')
    # Below is the static file path if you want to work on the same file
    file_path = '/Users/abhinavreddy/Downloads/standalone_incdev_analysis/input/logfile1.csv'
    # file_path = '/Users/abhinavreddy/Desktop/Standalone_tools/zylab_log-runs-UCRCS010AWinter2021_CH1.csv'
    filename = os.path.basename(file_path)
    logfile = pd.read_csv(file_path)
    logfile = logfile[logfile.role == 'Student']
    urls = logfile.zip_location.to_list()
    num_of_files_to_download = len(urls)
    selected_labs = get_selected_labs(logfile)
    data = {}
    final_roster = {}
    Styleanomaly = {
        'Pointers': [1, 0.9, 1, r'(\(+)?((int)|(char)|(string)|(void)|(bool)|(float)|(double)){1}(\)+)?(\s+)?\*{1,2}(\s+)?[a-zA-Z]+(\s+)?(\=)?.*\;$', 0],
        'Infinite_loop': [0, 0.9, 1, r'(while(\s+)?\((true|1)\))|(for(\s+)?\(;;\))', 0],
        'Atypical Includes': [1, 0.1, 1, r'#(\s+)?include(\s+)?<((iomanip)|(algorithm)|(cstdlib)|(utility)|(limits)|(cmath))>', 0],
        'Atypical Keywords': [1, 0.3, 1, r'((break(\s+)?;)|(switch(\s+)?\(.*\)(\s+)?{)|(continue(\s+)?;)|(sizeof\(.*\))|(case\s+([a-zA-Z0-9]+(\s+)?:)))', 0],
        'Array Accesses': [1, 0.9, 1, r'([a-zA-Z0-9]+\[.*\])', 0],
        'Namespace Std': [1, 0.1, 1, r'(std::)', 0],
        'Brace Styling': [1, 0.1, 1, r'^((\s+)?{)', 0],
        'Escaped Newline': [1, 0.1, 1, r'(\\n)', 0],
        'User-Defined Functions': [1, 0.8, 1, r'^(((unsigned|signed|long|short)\s)?\S{3,}\s+\S+\(.*\))', 0],
        'Ternary Operator': [1, 0.2, 1, r'(.+\s+\?\s+.+\s+:\s+.+)', 0],
        'Command-Line Arguments': [1, 0.8, 1, r'(int argc, (char\s?\*\s?argv\[\]|char\s?\*\*\s?argv|char\s?\*\[\]\s?argv))', 0],
        'Nulls': [1, 0.4, 1, r'(?i)(nullptr|null|\\0)', 0],
        'Scope Operator': [1, 0.25, 1, r'(\S+::\S+)', 0]
    }
    while(1):
        print(" 1. Quick Analysis (average by lab) \n 2. Basic statisics (roster) \n 3. Anomalies (regex) \n 4. Coding Trails \n 5. Style anomalies (cpp lint) \n 6. Quit")
        inp = input()
        final_roster = {}
        # print(list(inp.split(' '))
        input_list = inp.split(' ')
        # print(input_list)
        for i in input_list:
            inp = int(i)

            if inp == 1:
                quick_analysis(logfile)
            
            elif inp == 2:
                final_roster = roster(logfile, selected_labs)

            elif inp == 3:
                if data == {}:
                    logfile = download_code(logfile)
                    data = create_data_structure(logfile)
                anomaly_detection_output = anomaly(data, selected_labs, Styleanomaly)
                for user_id in anomaly_detection_output:
                    # print(anomaly_detection_output[user_id])
                    # break
                    for lab in anomaly_detection_output[user_id]:
                        anomalies_found = anomaly_detection_output[user_id][lab][0]
                        anomaly_score = anomaly_detection_output[user_id][lab][1]
                        if user_id in final_roster:
                            final_roster[user_id]['Lab ' + str(lab) + ' anomalies found'] = anomalies_found
                            final_roster[user_id]['Lab ' + str(lab) + ' anomaly score'] = anomaly_score
                            final_roster[user_id][str(lab) + ' Student code'] = anomaly_detection_output[user_id][lab][2]
                        else:
                            final_roster[user_id] = {
                                'User ID': user_id,
                                'Last Name': data[user_id][lab][0].last_name[0],
                                'First Name': data[user_id][lab][0].first_name[0],
                                'Email': data[user_id][lab][0].email[0],
                                'Role': 'Student',
                                'Lab ' + str(lab) + ' anomalies found' : anomalies_found,
                                'Lab ' + str(lab) + ' anomaly score' : anomaly_score,
                                str(lab) + ' Student code' : anomaly_detection_output[user_id][lab][2]
                            }
                # print(final_roster)
            
            elif inp == 4:
                if data == {}:
                    logfile = download_code(logfile)
                    data = create_data_structure(logfile)
                # Generate nested dict of IncDev results
                incdev_output = incdev.run(data)
                for user_id in incdev_output:
                    for lab_id in incdev_output[user_id]:
                        lid = str(lab_id)
                        score = incdev_output[user_id][lab_id]['incdev_score']
                        score_trail = incdev_output[user_id][lab_id]['incdev_score_trail']
                        loc_trail = incdev_output[user_id][lab_id]['loc_trail']
                        time_trail = incdev_output[user_id][lab_id]['time_trail']
                        code = incdev_output[user_id][lab_id]['Highest_code']
                        if user_id in final_roster:
                            final_roster[user_id][lid + ' incdev_score'] = score
                            final_roster[user_id][lid + ' incdev_score_trail'] = score_trail
                            final_roster[user_id][lid + ' loc_trail'] = loc_trail
                            final_roster[user_id][lid + ' time_trail'] = time_trail
                            final_roster[user_id][str(lid) + ' Student code'] = code
                        else:
                            final_roster[user_id] = {
                                'User ID': user_id,
                                'Last Name': data[user_id][lab_id][0].last_name[0],
                                'First Name': data[user_id][lab_id][0].first_name[0],
                                'Email': data[user_id][lab_id][0].email[0],
                                'Role': 'Student',
                                lid + ' incdev_score' : score,
                                lid + ' incdev_score_trail' : score_trail,
                                lid + ' loc_trail' : loc_trail,
                                lid + ' time_trail' : time_trail,
                                str(lab_id) + ' Student code' : code
                            }
            
            elif inp == 5:
                if data == {}:
                    logfile = download_code(logfile)
                    data = create_data_structure(logfile)
                stylechecker_output = stylechecker(data, selected_labs)
                for user_id in stylechecker_output:
                    for lab_id in stylechecker_output[user_id]:
                        if user_id in final_roster:
                            final_roster[user_id][str(lab_id) + 'Style score'] = stylechecker_output[user_id][lab_id][0]
                            final_roster[user_id][str(lab_id) + 'Style output'] = stylechecker_output[user_id][lab_id][1]
                            final_roster[user_id][str(lab_id) + ' Student code'] = stylechecker_output[user_id][lab_id][2]
                        else:
                            final_roster[user_id] = {
                                'User ID': user_id,
                                'Last Name': data[user_id][lab_id][0].last_name[0],
                                'First Name': data[user_id][lab_id][0].first_name[0],
                                'Email': data[user_id][lab_id][0].email[0],
                                'Role': 'Student',
                                str(lab_id) + '  Style score' : stylechecker_output[user_id][lab_id][0],
                                str(lab_id) + '  Style output' : stylechecker_output[user_id][lab_id][1],
                                str(lab_id) + ' Student code' : stylechecker_output[user_id][lab_id][2]
                            }
            
            elif inp == 6:
                exit(0)
            
            else:
                print("Please select a valid option")
        
        if len(final_roster) != 0:
            write_output_to_csv(final_roster)

def main(id, selected_labs, selected_options, file_path, options):
    logfile = pd.read_csv(file_path)
    logfile = logfile[logfile.role == 'Student']
    urls = logfile.zip_location.to_list()
    num_of_files_to_download = len(urls)
    data = {}
    final_roster = {}
    input_list = selected_options
    for inp in input_list:

        if inp == 1:
            return [num_of_files_to_download, quick_analysis(logfile)]
        
        elif inp == 2:
            final_roster = roster(logfile, selected_labs)

        elif inp == 3:
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            anomaly_detection_output = anomaly(data, selected_labs, options['Styleanomaly'])
            for user_id in anomaly_detection_output:
                # print(anomaly_detection_output[user_id])
                # break
                for lab in anomaly_detection_output[user_id]:
                    anomalies_found = anomaly_detection_output[user_id][lab][0]
                    anomaly_score = anomaly_detection_output[user_id][lab][1]
                    if user_id in final_roster:
                        final_roster[user_id]['Lab ' + str(lab) + ' anomalies found'] = anomalies_found
                        final_roster[user_id]['Lab ' + str(lab) + ' anomaly score'] = anomaly_score
                        final_roster[user_id][str(lab) + ' Student code'] = anomaly_detection_output[user_id][lab][2]
                    else:
                        final_roster[user_id] = {
                            'User ID': user_id,
                            'Last Name': data[user_id][lab][0].last_name[0],
                            'First Name': data[user_id][lab][0].first_name[0],
                            'Email': data[user_id][lab][0].email[0],
                            'Role': 'Student',
                            'Lab ' + str(lab) + ' anomalies found' : anomalies_found,
                            'Lab ' + str(lab) + ' anomaly score' : anomaly_score,
                            str(lab) + ' Student code' : anomaly_detection_output[user_id][lab][2]
                        }
        
        elif inp == 4:
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            # Generate nested dict of IncDev results
            incdev_output = incdev.run(data)
            for user_id in incdev_output:
                for lab_id in incdev_output[user_id]:
                    lid = str(lab_id)
                    score = incdev_output[user_id][lab_id]['incdev_score']
                    score_trail = incdev_output[user_id][lab_id]['incdev_score_trail']
                    loc_trail = incdev_output[user_id][lab_id]['loc_trail']
                    time_trail = incdev_output[user_id][lab_id]['time_trail']
                    code = incdev_output[user_id][lab_id]['Highest_code']
                    if user_id in final_roster:
                        final_roster[user_id][lid + ' incdev_score'] = score
                        final_roster[user_id][lid + ' incdev_score_trail'] = score_trail
                        final_roster[user_id][lid + ' loc_trail'] = loc_trail
                        final_roster[user_id][lid + ' time_trail'] = time_trail
                        final_roster[user_id][str(lid) + ' Student code'] = code
                    else:
                        final_roster[user_id] = {
                            'User ID': user_id,
                            'Last Name': data[user_id][lab_id][0].last_name[0],
                            'First Name': data[user_id][lab_id][0].first_name[0],
                            'Email': data[user_id][lab_id][0].email[0],
                            'Role': 'Student',
                            lid + ' incdev_score' : score,
                            lid + ' incdev_score_trail' : score_trail,
                            lid + ' loc_trail' : loc_trail,
                            lid + ' time_trail' : time_trail,
                            str(lab_id) + ' Student code' : code
                        }
        
        elif inp == 5:
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            stylechecker_output = stylechecker(data, selected_labs)
            for user_id in stylechecker_output:
                for lab_id in stylechecker_output[user_id]:
                    if user_id in final_roster:
                        final_roster[user_id][str(lab_id) + 'Style score'] = stylechecker_output[user_id][lab_id][0]
                        final_roster[user_id][str(lab_id) + 'Style output'] = stylechecker_output[user_id][lab_id][1]
                        final_roster[user_id][str(lab_id) + ' Student code'] = stylechecker_output[user_id][lab_id][2]
                    else:
                        final_roster[user_id] = {
                            'User ID': user_id,
                            'Last Name': data[user_id][lab_id][0].last_name[0],
                            'First Name': data[user_id][lab_id][0].first_name[0],
                            'Email': data[user_id][lab_id][0].email[0],
                            'Role': 'Student',
                            str(lab_id) + '  Style score' : stylechecker_output[user_id][lab_id][0],
                            str(lab_id) + '  Style output' : stylechecker_output[user_id][lab_id][1],
                            str(lab_id) + ' Student code' : stylechecker_output[user_id][lab_id][2]
                        }
        
        elif inp == 6:
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            return detailedview(id, logfile, data, options)

        elif inp == 7:
            exit(0)
        
        else:
            print("Please select a valid option")
        
        #Adding N/A to empty columns
        #Fiding all columns
        columns = []
        for id in final_roster:
                for column in final_roster[id]:
                    # print(summary_roster[id])
                    if column not in columns:
                        columns.append(column) 
        #Detecting missing columns and adding N/A
        for id in final_roster:
            for col in columns:
                if col not in final_roster[id]:
                    final_roster[id][col] = 'N/A'

    return final_roster

def sayhello():
    return "hello from say hello"

    