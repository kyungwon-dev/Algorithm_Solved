def solution(arr):
    answer = 1
    for i in range(0, len(arr), 1):
        for j in range(0, len(arr)):
            if arr[i][j] != arr[j][i]:
                return 0
    return answer