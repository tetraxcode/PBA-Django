from tools.zytools.tools.roster import roster
from tools.zytools.tools import incdev
from tools.zytools.tools.submission import Submission
from tools.zytools.tools.similarity import similarity_of_one_student
from difflib import Differ

differ_inst = Differ()

##############################
#       Helper Functions     #
##############################

def get_label_data(input, option):
    if option == 'score_trail':
        y =  input.split(',')
        data = []
        label = []
        suspicious = []
        count = 1
        for item in y:
            label.append(count)
            var = item.split()[0]
            if var[0] == '^':
                data.append(int(var.strip('^')))
                suspicious.append(1)
            else:
                data.append(int(var))
                suspicious.append(0)
            count += 1
    return label, data, suspicious

def find_code_diff(code1, code2):
    deltas = list(differ_inst.compare(code1.splitlines(), code2.splitlines()))
    # print(deltas)
    code_diff = ''
    for line in deltas:
        # if line[0] == '+':
        #     line = '<mark>' + line + '</mark>' + '\n'
        code_diff += line + '\n'
    return code_diff

##############################
#       User Functions       #
##############################

def detailedview(id, logfile, data, options):
    '''
    Input:
    ------
        Accepts a student id, logfile, data and additional options as an input 
    
    Output:
    -------
        Returns a result structure containing the following 
        result = {
            'First_Name':   'John',
            'Last_Name':    'Doe',
            'Email':        'jdoe001@ucr.edu',
            ...
            ...
            ...
            ...
            ...
        }
    '''
    result = {}
    labs = logfile.content_section.unique()
    details = data[int(id)]
    roster_details = roster(logfile, labs)[int(id)]
    result['First_Name'] = roster_details['First Name']
    result['Last_Name'] = roster_details['Last Name']
    result['Email'] = roster_details['Email']
    result['User_ID'] = roster_details['User ID']
    result['Role'] = roster_details['Role']
    result['Total_Score'] = roster_details['Total Score']
    result['Total_Runs'] = roster_details['Total Runs']
    result['Total_Develops'] = roster_details['Total Develops']
    result['Total_Submits'] = roster_details['Total Submits']
    result['Labs'] = {}
    
    data_id = {int(id) : data[int(id)]}
    incdev_data = incdev.run(data_id)[int(id)]

    # Finding differences between two code submissions 
    if 'diff_code' in options:
        element1 = options['diff_code'][0].split('_')
        element2 = options['diff_code'][1].split('_')
        lab1, submission_id_1 = float(element1[0]), element1[1]
        lab2, submission_id_2 = float(element2[0]), element2[1]
        for sub in details[lab1]:
            if sub.submission_id == submission_id_1:
                code1 = sub.code
        for sub in details[lab2]:
            if sub.submission_id == submission_id_2:
                code2 = sub.code
        code_diff = find_code_diff(code1, code2)
        if lab1 not in result['Labs']:
            result['Labs'][lab1] = {}
        result['Labs'][lab1]['code_diff'] = code_diff
        result['Labs'][lab1]['code_before'] = code1
        result['Labs'][lab1]['code_after'] = code2

    for lab in labs:
        if lab in incdev_data:
            if lab not in result['Labs']:
                result['Labs'][lab] = {}
            incdev_score_trail = incdev_data[lab]['incdev_score_trail']
            loc_trail = incdev_data[lab]['loc_trail']
            time_trail = incdev_data[lab]['time_trail']
            score_trail_label, score_trail_data, suspicious = get_label_data(incdev_score_trail, 'score_trail')
            result['Labs'][lab]['submissions'] = details[lab]
            for i, submission in enumerate(result['Labs'][lab]['submissions']):
                if i == 0:
                    submission.code_diff = submission.code
                else:
                    code1 = result['Labs'][lab]['submissions'][i-1].code
                    code2 = submission.code
                    code_diff = find_code_diff(code1, code2)
                    submission.code_diff = code_diff
            for i in range(len(suspicious)):
                if suspicious[i] == 1:
                    result['Labs'][lab]['submissions'][i].suspicious = 'yes'
            result['Labs'][lab]['incdev_score_trail'] = incdev_score_trail
            result['Labs'][lab]['score_trail_label'] = score_trail_label
            result['Labs'][lab]['score_trail_data'] = score_trail_data
            result['Labs'][lab]['loc_trail'] = loc_trail
            result['Labs'][lab]['time_trail'] = time_trail
    
    if 'get similarities' in options:
        similarity = similarity_of_one_student(id, labs, data)
        id = int(id)
        for lab in similarity[id]:
            if lab in result['Labs']:
                result['Labs'][lab]['similarity_max'] = similarity[id][lab]['similarity_max']
                result['Labs'][lab]['similarity'] = similarity[id][lab]['similarity']

    return result