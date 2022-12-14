from django.shortcuts import render
from django.core.files.storage import FileSystemStorage
import os

from markupsafe import re
from tools.zytools.main import main as zytools_main

import pandas as pd

# Create your views here.

def home(request):
    def update_Styleanomaly(request, Styleanomaly):
        # data = Styleanomaly
        # print('hello')
        # print(request)
        for anomaly in Styleanomaly:
            if anomaly+'_disabled' in request:
                Styleanomaly[anomaly][2] = 0
            else:
                Styleanomaly[anomaly][2] = 1
            if anomaly+'_count_true' in Styleanomaly:
                Styleanomaly[anomaly][0] = 1
            else:
                Styleanomaly[anomaly][0] = 0
            Styleanomaly[anomaly][1] = float(request.getlist(anomaly+'_score')[0])
        # print(Styleanomaly)
        return Styleanomaly
    # [Count_instances, Points/instance, anomaly on/off, regex, whether its used for once (used for !count instances)]
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

    context = {'anomaly_options': Styleanomaly}
    file_path = ''
    if request.method == 'POST':
        selected_options = []
        # print(request.POST)
        if 'Generate_Roster' in request.POST:
            selected_labs = [float(i) for i in request.POST.getlist("checkbox_labs")]
            selected_tools = request.POST.getlist("checkbox_options")
            print(selected_tools)
            if 'Roster' in selected_tools:
                selected_options.append(2)
            if 'Anomalies' in selected_tools:
                Styleanomaly = update_Styleanomaly(request.POST, Styleanomaly)
                selected_options.append(3)
            if 'Coding Trails' in selected_tools:
                selected_options.append(4)
            if 'Style Anomalies' in selected_tools:
                selected_options.append(5)
            if 'Similarities' in selected_tools:
                selected_options.append(7)
            roster = zytools_main(0, selected_labs, selected_options, 'media/logfile.csv', {'Styleanomaly' : Styleanomaly})
            # print(roster)
            columns = []
            summary = zytools_main(0, selected_labs, [1], 'media/logfile.csv', {'Styleanomaly' : Styleanomaly})
            for id in roster:
                for column in roster[id]:
                    # print(summary_roster[id])
                    if column not in columns:
                        columns.append(column) 
            # request.session['roster'] = roster
            # print(roster)
            # print(roster)
            # print(selected_labs)
            print(summary)
            context = {'roster' : roster,
                        'columns': columns,
                        'entry': summary[1],
                        'anomaly_options': Styleanomaly
                        }
        else:
            # print(request.content_type)
            f = request.FILES['log_file']
            if os.path.exists('media/logfile.csv'):
                os.remove('media/logfile.csv')
            fs = FileSystemStorage()
            fs.save('logfile.csv', f)
            file_path = 'media/logfile.csv'
            selected_labs = [0]

            #Checking if the uploaded logfile contains all the required headers
            headers = pd.read_csv('media/logfile.csv', index_col=0, nrows=0).columns.tolist()
            # print(headers)
            # user_id, content_section, content_resource_id, caption, first_name, last_name, email, zip_location,
            # submission, score, date_submitted
            required_headers = ["user_id", "content_section", "content_resource_id", "caption", "first_name", "last_name", "email", "zip_location", "submission", "score", "date_submitted"]
            if not all(item in headers for item in required_headers):
                return render(request, 'zytools/home.html', {"message": "missing headers", "required_headers": f"Required headers: {required_headers}", "headers": f"Headers in the uploaded file: {headers}"})
            

            selected_options = [1]
            summary = zytools_main(0, selected_labs, selected_options, file_path, {'Styleanomaly' : Styleanomaly})

            context = {'entry': summary[1],
            'files_to_download': summary[0],
            'anomaly_options': Styleanomaly
            }

            # print(summary)
    
    return render(request, 'zytools/home.html', context)

def about(request):
    return render(request, 'zytools/about.html')

def view(request, userid):
    file_path = 'media/logfile.csv'
    options = {}
    if request.method == "POST":
        print(request.POST)
        diff_code = []
        if "Get differences" in request.POST:
            diff_code = [i for i in request.POST.getlist("checkbox_labs")]
            options['diff_code'] = diff_code
        if 'get similarities' in request.POST:
            options['get similarities'] = ''
        result = zytools_main(userid, [0], [6], file_path, options)
        diff_code.clear()
    else:
        result = zytools_main(userid, [0], [6], file_path, {})
    context = {'userid': userid,
    'result' : result
    }
    return render(request, 'zytools/view.html', context)