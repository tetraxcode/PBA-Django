from asyncio import as_completed
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime
from re import X
import copydetect
from pygments.lexers.c_cpp import CppLexer
from pygments import lex
from pygments.token import Token as ParseToken
import difflib
from bs4 import BeautifulSoup
from concurrent.futures import ThreadPoolExecutor, as_completed

##############################
#       Helper Functions     #
##############################

def getMoss(code1, code2):
    '''
    Uses a modified version of the Copydetect package which has Moss similarity detection capabilities
    Input:
    ------
        Accepts two different code runs 
    
    Output:
    -------
        Returns similarity and html highlighting differences 
    '''
    fp1 = copydetect.CodeFingerprint( (code1), 25, 1)
    fp2 = copydetect.CodeFingerprint( (code2), 25, 1)
    token_overlap, similarities, slices = copydetect.compare_files(fp1, fp2)
    test_sim = similarities[1]
    ref_sim = similarities[0]
    slices_test = slices[1]
    slices_ref = slices[0]
    detector = copydetect.CopyDetector
    soup = BeautifulSoup(detector.generate_html_report(fp1, fp2, test_sim, ref_sim, slices_test, slices_ref, token_overlap), 'html.parser')
    code = soup.find_all('div', class_='col')
    html = f'''
    <table>
        <tr>
            <td style="padding:1%; border-right: 1px solid black;">
                {code[2]}
            </td>
            <td style="padding: 1%;">
                {code[3]}
            </td>
        </tr>
    </table>
    '''
    test_sim *= 100
    return round(test_sim, 2) , html
#*************************************************************
def removeNoise(code):
    code = removeComments(code)                    # remove comments
    code = removeEmptyLines(code)                    # remove comments
    return code
#*************************************************************
def removeEmptyLines(code):
    code = code.splitlines(True)
    lines = [line for line in code if line.strip()] # remove empty lines
    code = ""
    for line in lines:
        code+=line
    return code
#*************************************************************
def removeComments(code):
    lexer = CppLexer()
    generator = lex(code, lexer)
    line = []
    lines = []
    for token in generator:
        # print(token)
        token_type = token[0]
        token_text = token[1]
        if token_type in ParseToken.Comment.Multiline or token_type in ParseToken.Comment.Single:
            # print('skpped >>>', token_text )
            if '\n' in token_text:
                line.append('\n')
            continue
        line.append(token_text)
        if token_text == '\n':
            lines.append(''.join(line))
            line = []
    if line:
        line.append('\n')
        lines.append(''.join(line))
    strip_query = "".join(lines)
    return strip_query
#**************************************************************

##############################
#       User Functions       #
##############################

def similarity_of_highest_scoring_code_submissions(selected_labs, data):
    '''
    Compares each students latest highest scoring submission with every students latest highest scoring submission
    Input:
    ------
        Accepts selected labs and data as an input 
    
    Output:
    -------
        Returns a structure containing similarity scores
        result = {
            student_id: {
                lab1 : {
                    similarity: [
                        [submission1, submission2, similarity_score],
                        [submission1, submission2, similarity_score]
                        ...
                        ...
                        ...
                    ],
                    similarity_max = 0
                },
                ...
                ...
                ...
            },
            ...
            ...
            ...
        }
    '''

    result = {}

    for lab in selected_labs:
        for user_id_1 in data:
            if lab not in data[user_id_1]:
                continue
            if user_id_1 not in result:
                result[user_id_1] = {}
            if lab not in result:
                result[user_id_1][lab] = {"similarity": []}
                result[user_id_1][lab]["similarity_max"] = 0
            max_score = 0
            similarity_max = 0
            student_code_1 = ""
            submission1 = None
            for submission1 in data[user_id_1][lab]:
                if submission1.max_score >= max_score:
                    student_code_1 = submission1.code
            for user_id_2 in data:
                if lab not in data[user_id_2]:
                    continue
                student_code_2 = ""
                submission2 = None
                if user_id_1 != user_id_2:
                    for submission2 in data[user_id_2][lab]:
                        if submission2.max_score >= max_score:
                            student_code_2 = submission2.code

                aCodeNC = removeNoise(student_code_1) # remove emtpy lines and comments
                bCodeNC = removeNoise(student_code_2) # remove emtpy lines and comments

                # Calculating sim 
                sim, table_html = getMoss(student_code_1, student_code_2)
                simNC, table_html_NC = getMoss(aCodeNC, bCodeNC)
                simMax = max(sim, simNC)
                similarity_max = max(similarity_max, simMax)
                result[user_id_1][lab]["similarity"].append([submission1, submission2, simMax])
        if user_id_1 in result:
            result[user_id_1][lab]["similarity_max"] = similarity_max
    return result

def similarity_of_one_student(student_id, selected_labs, data):
    '''
    Compares one students latest highest scoring submission with every other students latest highest scoring submission
    Input:
    ------
        Accepts a student id, selected labs and data as an input 
    
    Output:
    -------
        Returns a structure containing similarity scores
        result = {
            student_id: {
                lab1 : {
                    similarity: [
                        [submission1, submission2, similarity_score],
                        [submission1, submission2, similarity_score]
                        ...
                        ...
                        ...
                    ],
                    similarity_max = 0
                },
                ...
                ...
                ...
            },
            ...
            ...
            ...
        }
    '''

    result = {}

    user_id_1 = int(student_id)

    for lab in selected_labs:
        if user_id_1 not in result:
            result[user_id_1] = {}
        if lab not in result:
            result[user_id_1][lab] = {"similarity": []}
            result[user_id_1][lab]["similarity_max"] = 0
        max_score = 0
        similarity_max = 0
        student_code_1 = ""
        submission1 = None
        if lab in data[user_id_1]:
            for submission1 in data[user_id_1][lab]:
                if submission1.max_score >= max_score:
                    student_code_1 = submission1.code
            
            #Adding multithreading
            threads = []
            with ThreadPoolExecutor(40) as executor:
                for user_id_2 in data:
                    student_code_2 = ""
                    submission2 = None
                    if user_id_1 != user_id_2:
                        if lab in data[user_id_2]:
                            for submission2 in data[user_id_2][lab]:
                                if submission2.max_score >= max_score:
                                    student_code_2 = submission2.code

                    aCodeNC = removeNoise(student_code_1) # remove emtpy lines and comments
                    bCodeNC = removeNoise(student_code_2) # remove emtpy lines and comments
                    threads.append(executor.submit(getMoss, aCodeNC, bCodeNC))
                    for task in as_completed(threads):
                        simMax, table_html_NC = task.result()
                        similarity_max = max(similarity_max, simMax)
                        result[user_id_1][lab]["similarity"].append([submission1, submission2, simMax, str(table_html_NC)])
        
        result[user_id_1][lab]["similarity"].sort(key= lambda x:x[2], reverse = True)
        result[user_id_1][lab]["similarity_max"] = similarity_max

    return result

