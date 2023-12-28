def solution(myString, pat):
    answer = ''
    while myString.find(pat) != -1:
        answer = answer +  myString[:myString.find(pat) + len(pat)]
        myString = myString[myString.find(pat) + len(pat):]
    return answer