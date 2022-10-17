from tools.zytools.tools.roster import roster
from tools.zytools.tools import incdev

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


def detailedview(id, logfile, data):
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
    # incdev_score_trail = incdev_data['incdev_score_trail']
    # loc_trail = incdev_data['loc_trail']
    # time_trail = incdev_data['time_trail']

    for lab in labs:
        if lab in incdev_data:
            if lab not in result['Labs']:
                result['Labs'][lab] = {}
            incdev_score_trail = incdev_data[lab]['incdev_score_trail']
            loc_trail = incdev_data[lab]['loc_trail']
            time_trail = incdev_data[lab]['time_trail']
            score_trail_label, score_trail_data, suspicious = get_label_data(incdev_score_trail, 'score_trail')
            result['Labs'][lab]['submissions'] = details[lab]
            for i in range(len(suspicious)):
                if suspicious[i] == 1:
                    result['Labs'][lab]['submissions'][i].suspicious = 'yes'
            result['Labs'][lab]['incdev_score_trail'] = incdev_score_trail
            result['Labs'][lab]['score_trail_label'] = score_trail_label
            result['Labs'][lab]['score_trail_data'] = score_trail_data
            result['Labs'][lab]['loc_trail'] = loc_trail
            result['Labs'][lab]['time_trail'] = time_trail
    
    
    
    # print(incdev_score_trail, loc_trail, time_trail)
    # print(incdev_data)
    # print(roster_details)
    # print(result)

    return result