def solution(strArr):
    answer = [0 for _ in range(100000)]
    for str in strArr:
        answer[len(str)-1]+=1
    return max(answer)