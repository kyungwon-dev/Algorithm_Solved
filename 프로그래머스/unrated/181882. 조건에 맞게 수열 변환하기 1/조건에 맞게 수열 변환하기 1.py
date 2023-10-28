def solution(arr):
    answer = []
    for a in arr:
        if a%2 == 0 and a>= 50:
            answer.append(a/2)
        elif a%2 == 1 and a< 50:
            answer.append(a*2)
        else:
            answer.append(a)
    return answer

