def solution(myString, pat):
    revString = "".join(["A" if i == "B" else "B" for i in myString])    
    return 1 if pat in revString else 0