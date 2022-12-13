import copydetect
from pygments.lexers.c_cpp import CppLexer
from pygments import lex
from pygments.token import Token as ParseToken
import difflib
from bs4 import BeautifulSoup

def getMoss(code1, code2):

    fp1 = copydetect.CodeFingerprint( (code1), 25, 1)
    fp2 = copydetect.CodeFingerprint( (code2), 25, 1)
    token_overlap, similarities, slices = copydetect.compare_files(fp1, fp2)
    test_sim = similarities[1]
    ref_sim = similarities[0]
    slices_test = slices[1]
    slices_ref = slices[0]
    # print(test_sim, ref_sim, slices_test, slices_ref, token_overlap)
    detector = copydetect.CopyDetector
    soup = BeautifulSoup(detector.generate_html_report(fp1, fp2, test_sim, ref_sim, slices_test, slices_ref, token_overlap), 'html.parser')
    # print(soup.prettify())
    code = soup.find_all('div', class_='col')
    # print(code[2])
    # print(code[3])
    html = f'''
    <table>
        <tr>
            <td>
                {code[2]}
            </td>
            <td>
                {code[3]}
            </td>
        </tr>
    </table>
    '''
    # print(soup)
    test_sim *= 100
    return test_sim, html
#*************************************************************    
def get_similarities(code1, code2):
    fp1 = copydetect.CodeFingerprint( (code1), 25, 1)
    fp2 = copydetect.CodeFingerprint( (code2), 25, 1)
    token_overlap, similarities, slices = copydetect.compare_files(fp1, fp2)

    return round(similarities[0],1), round(similarities[1],1)
#*************************************************************
def getLOC(code):
    code = code.splitlines(True)
    lines = [line for line in code if line.strip()]
    return len(lines)
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
def compare2Runs(run1, run2):

    runA = run1.splitlines(True)
    runB = run2.splitlines(True)

    htmlDiff = difflib.HtmlDiff(wrapcolumn=85).make_file(runA, runB)
    soup = BeautifulSoup(htmlDiff, 'html.parser')
    table = soup.find("table", {"class": "diff"})
    counter = 0
    codeA = {}
    codeB = {}
    i = 0
    j = 0
    for td in soup.tbody.find_all('td'):
        if td.attrs == {'nowrap': 'nowrap'}:
            if counter % 2 ==0:
                codeA[i] = str(td)
                i += 1
            else:
                codeB[j] = str(td)
                j += 1
        counter+=1

    adds = soup.tbody.find_all("span", class_="diff_add")
    changes = soup.tbody.find_all("span", class_="diff_chg")
    deletions = soup.tbody.find_all("span", class_="diff_sub")

    addChar = ''
    changeChar = ''
    deleteChar = ''

    for add in adds:
        # print('len(add)=',len(add),'<br>')
        if len(add) != 0:
            addChar += add.string

    for change in changes:
        if len(change) != 0:
            changeChar += change.string

    for deleteion in deletions:
        if len(deleteion) != 0:
            deleteChar += deleteion.string

    return codeA, codeB, addChar, changeChar, deleteChar, table
#*************************************************************
def getMySim(a, b):# Python HtmlDiff version

    aTemp, bTemp, addChar, chChar, delChar, table_html = compare2Runs(a, b)

    delta = len(addChar) + len(chChar) + len(delChar)
    total = len(a)+len(b)
    # if debug:
    #     print('len(aNC)+len(bNC)=',len(a)+len(b),'<br>')
    if total !=0:
        mySim = round(1-(delta/total),1)
    else:
        mySim = 0
    return mySim, table_html
#**************************************************************
def getSim(aCode, bCode):
    aCodeLOC = getLOC(aCode)
    bCodeLOC = getLOC(bCode)

    aCodeNC = removeNoise(aCode) # remove emtpy lines and comments
    bCodeNC = removeNoise(bCode) # remove emtpy lines and comments

    aCodeNC_LOC = getLOC(aCodeNC)
    bCodeNC_LOC = getLOC(bCodeNC)

    # Calculating sim 
    sim = getMySim(aCode, bCode)
    simNC = getMySim(aCodeNC, bCodeNC)
    simMax = max(sim, simNC)
    return round(simMax,2)
#**************************************************************
def similarity_of_highest_scoring_code_submissions(student_id, selected_labs, data):

    result = {}
    '''
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

    for lab in selected_labs:
        for user_id_1 in data:
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
                student_code_2 = ""
                submission2 = None
                if user_id_1 != user_id_2:
                    for submission2 in data[user_id_2][lab]:
                        if submission2.max_score >= max_score:
                            student_code_2 = submission2.code

                aCodeNC = removeNoise(student_code_1) # remove emtpy lines and comments
                bCodeNC = removeNoise(student_code_2) # remove emtpy lines and comments

                # Calculating sim 
                sim, table_html = getMySim(student_code_1, student_code_2)
                simNC, table_html_NC = getMySim(aCodeNC, bCodeNC)
                simMax = max(sim, simNC)
                similarity_max = max(similarity_max, simMax)
                result[user_id_1][lab]["similarity"].append([submission1, submission2, simMax])
        result[user_id_1][lab]["similarity_max"] = similarity_max
    return result

def similarity_of_one_student(student_id, selected_labs, data):

    result = {}
    '''
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

                # Calculating sim 
                # sim, table_html = getMySim(student_code_1, student_code_2)
                # simNC, table_html_NC = getMySim(aCodeNC, bCodeNC)
                sim, table_html = getMoss(student_code_1, student_code_2)
                simNC, table_html_NC = getMoss(aCodeNC, bCodeNC)
                simMax = max(sim, simNC)
                similarity_max = max(similarity_max, simMax)
                result[user_id_1][lab]["similarity"].append([submission1, submission2, simMax, str(table_html)])
        result[user_id_1][lab]["similarity"].sort(key= lambda x:x[2], reverse = True)
        result[user_id_1][lab]["similarity_max"] = similarity_max
    
    # print(result)

    return result

