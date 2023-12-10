def solution(n):
    answer = [[0 for i in range(n)] for j in range(n)]
    for i in range(0, n, 1):
        for j in range(0, n, 1):
            if i==j:
                answer[i][j] = 1
    return answer