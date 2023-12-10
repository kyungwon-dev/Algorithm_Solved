def solution(myString):
    answer = []
    for mystr in  myString.split("x"):
        if mystr == "":
            continue
        answer.append(mystr)
    answer.sort()
    return answer