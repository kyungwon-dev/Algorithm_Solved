def solution(myString):
    myString = list(map(lambda x : 'A' if x=='a' else x.lower() if x != 'A' else x, myString))
    return "".join(myString)