def solution(numLog):
    answer = ''
    for i in range(1, len(numLog)):
        if numLog[i-1] + 1 == numLog[i]:
            answer = answer + "w" 
        elif numLog[i-1] - 1 == numLog[i]:
            answer = answer + "s" 
        elif numLog[i-1] + 10 == numLog[i]:
            answer = answer + "d" 
        else:
            answer = answer + "a" 
    return answer