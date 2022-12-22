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
from tools.zytools.tools.similarity import similarity_of_highest_scoring_code_submissions
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
    '''
    There are lots of different datetime formats, this function accounts for those and returns the timestamp
    '''
    t = timestamp
    for fmt in ('%m/%d/%Y %H:%M:%S', '%Y-%m-%d %H:%M:%S', '%m/%d/%Y %H:%M:%S','%m/%d/%y %H:%M', '%m/%d/%Y %H:%M'):
        try:
            return datetime.strptime(t, fmt)
        except ValueError:
            pass
    raise ValueError('Cannot recognize datetime format: ' + t)

def download_code_helper(url):
    '''
    Actual code which downloads the students code run using requests library
    '''
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
    '''
    Iterates through the zybooks logfile dataframe and appends a new column "student_code" to the dataframe and return it 

    Note: This is the fastest way to download code submissions of all students at this time. We tried AsyncIO but it turned out to be slower than multithreading
    '''
    urls = logfile.zip_location.to_list()
    student_code = []
    threads = []
    print("Downloading student code...")
    start = datetime.now()
    with ThreadPoolExecutor(400) as executor:
        for url in urls:
            threads.append(executor.submit(download_code_helper, url))
        student_code = []
        for task in as_completed(threads):
            student_code.append(task.result())
    df = pd.DataFrame(student_code, columns = ['zip_location', 'student_code'])
    logfile = pd.merge(left=logfile, right=df, on=['zip_location'])
    end = datetime.now()
    print(f"Downloaded {len(urls)} files in {end-start}")
    return logfile

def get_selected_labs(logfile):
    '''
    Function to get selected labs from the user entered input
    '''
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
    '''
    This function writes our dataframe into a csv output file
    '''
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
    '''
    Creates a datastructure which stores all submission objects of each student

    data = {
        user_id_1: {
            lab_id_1 : [submission, submission, submission],
            lab_id_2 : [submission, submission, submission]
        }
        user_id_2: {
            lab_id_1 : [submission, submission, submission],
            lab_id_2 : [submission, submission, submission]
        }
        ...
        ...
        ...
    }

    '''
    data = {}
    for row in logfile.itertuples():
        if row.user_id not in data:
            data[int(row.user_id)] = {}
        if row.content_section not in data[row.user_id]:
            data[row.user_id][row.content_section] = []
        # lab_id = row.content_resource_id if content_resource_id
        # print(row)
        # if "content_resource_id" not in logfile:
        #     content_resource_id = row.lab_id
        # if "submission" not in logfile:
        #     is_submission = row.is_submission
        # if "date_submitted" not in logfile:
        #     date_submitted = row._11
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

# Below definition is used when the tool is in offline mode
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

#Below function is used when the tool needs to work with django (The above (if __name__ == '__main__") block will not be used)
def main(id, selected_labs, selected_options, file_path, options):
    '''
    Input:
    ------
        id: Student ID 
        selected_labs: Selected labs from the lab summary table 
        selected_options: Used to pass selected tools (ex: Coding Trails, Coding style, etc)
        file_path: Path where the uploaded logfile is saved (default: media/logfile.csv)
        options: Used to pass any additional bits of information needed to pass from the frontend, optional

    Returns:
    --------
        The returned structure (final_roster) changes according to the options selected 
        final_roster: {
            user_id_1: {
                user_id:            121314141,
                last_name:          'Doe,
                first_name:         'John',
                Email:              jdoe009@ucr.edu,
                Role:               student,
                points_per_minute:  0.0,
                'Time Spent(total)':'16m 00s',
                'Total Runs':       17,
                'Total Score':      10.0,
                'Total Develops':   8,
                'Total Submits':    9,
                'Total Pivots':     0,
                'Lab 1.2 Points per minute': 0.0,
                'Lab 1.2 Time spent': '16m 00s',
                'Lab 1.2 # of runs': 17,
                'Lab 1.2 % score': 10.0,
                'Lab 1.2 # of devs': 8,
                'Lab 1.2 # of subs': 9
                tool1_output: 'something',
                tool2_output: 'something,
                ...
                ...
                ...
            },
            ...
            ...
            ...
        }
        
        Depending on the selected options the tools outputs are added to this structure and returned to the frontend
    '''

    logfile = pd.read_csv(file_path)
    logfile = logfile[logfile.role == 'Student']
    urls = logfile.zip_location.to_list()
    num_of_files_to_download = len(urls)

    data = {} # Dataframe that holds details about all students including their code
    final_roster = {} # Final output to be returned
    input_list = selected_options 

    # Iterating through the selected tools from front end (ex: coding trails, coding style, etc)
    for inp in input_list:
        # 1. Quick Analysis (Lab Summary Table)
        if inp == 1:
            return [num_of_files_to_download, quick_analysis(logfile)]
        
        # 2. Roster 
        elif inp == 2:
            final_roster = roster(logfile, selected_labs)

        # 3. Style Anomalies 
        elif inp == 3:
            # Checking if the datastructure has not been created yet
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            
            # Sending data, labs and modified anomaly scores to the anomaly tool 
            anomaly_detection_output = anomaly(data, selected_labs, options['Styleanomaly'])
            for user_id in anomaly_detection_output:
                for lab in anomaly_detection_output[user_id]:
                    anomalies_found = anomaly_detection_output[user_id][lab][0]
                    anomaly_score = anomaly_detection_output[user_id][lab][1]
                    # IF the userid already exists in final_roster, appending additional columns 
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
        
        # 4. Coding Trails
        elif inp == 4:
            # Checking if the datastructure has not been created yet
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
                    # IF the userid already exists in final_roster, appending additional columns 
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
        
        # 5. Coding Style 
        elif inp == 5:
            # Checking if the datastructure has not been created yet
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            # Sending data, selected labs to stylechecker tool 
            stylechecker_output = stylechecker(data, selected_labs)
            for user_id in stylechecker_output:
                for lab_id in stylechecker_output[user_id]:
                    # IF the userid already exists in final_roster, appending additional columns 
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
        
        # 6. Detailed view (Students view page)
        elif inp == 6:
            # Checking if the datastructure has not been created yet
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            # Sending student id, logfile, data and additional options to detailed view tool
            return detailedview(id, logfile, data, options)

        # 7. Similarities 
        elif inp == 7:
            # Checking if the datastructure has not been created yet
            if data == {}:
                logfile = download_code(logfile)
                data = create_data_structure(logfile)
            #Sending student id, selected labs and data to the the similarity tool
            similarity = similarity_of_highest_scoring_code_submissions(id, selected_labs, data)
            for user_id in similarity:
                for lab_id in similarity[user_id]:
                    if user_id in final_roster:
                        final_roster[user_id][str(lab_id) + " Similarity"] = similarity[user_id][lab_id]['similarity_max']
                    else:
                        final_roster[user_id] = {
                            'User ID': user_id,
                            'Last Name': data[user_id][lab_id][0].last_name[0],
                            'First Name': data[user_id][lab_id][0].first_name[0],
                            'Email': data[user_id][lab_id][0].email[0],
                            'Role': 'Student',
                            str(lab_id) + " Similarity": similarity[user_id][lab_id]['similarity_max']
                        }

        # 8. Exit
        elif inp == 8:
            exit(0)
        
        # 9. Out of bounds 
        else:
            print("Please select a valid option")
        
        #Adding N/A to empty columns (Empty columns do exist because not every student might have submitted all the labs)
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

    