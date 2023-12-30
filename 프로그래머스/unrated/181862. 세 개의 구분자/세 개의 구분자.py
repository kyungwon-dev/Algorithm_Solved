import re
def solution(myStr):
    
    myStr = re.sub('[abc]+', ' ', myStr).strip()
    answer = myStr.split(' ')
    if answer[0] == '' :
        answer[0] = "EMPTY"
    return answer