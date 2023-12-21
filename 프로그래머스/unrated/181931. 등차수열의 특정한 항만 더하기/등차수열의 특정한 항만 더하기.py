def solution(a, d, included):
    answer = [i for i in range(a,d* len(included) + a - d + 1, d)]
    answer = sum([answer[i] if included[i] else 0 for i in range(0, len(answer), 1)])
    return answer