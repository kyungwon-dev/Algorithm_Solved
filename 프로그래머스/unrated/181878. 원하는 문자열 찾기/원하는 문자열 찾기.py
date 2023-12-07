def solution(myString, pat):
    pat , myString = myString.lower() , pat.lower()
    return 1 if myString in pat else 0