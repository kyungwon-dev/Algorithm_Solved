def solution(arr):
    if len(arr) == len(arr[0]):
        return arr
    row, col = len(arr), len(arr[0]);
    if row > col:
        col = row
    else:
        row = col
    answer = [ [0 for _ in range(col)] for _ in range(row)]
    for i in range(row):
        for j in range(col):
            if i >= len(arr):
                continue
            elif j >= len(arr[0]):
                continue
            else:
                answer[i][j] = arr[i][j]
    return answer