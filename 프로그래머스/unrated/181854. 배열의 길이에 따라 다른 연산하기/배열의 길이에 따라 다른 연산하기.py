def solution(arr, n):
    idx = 0 if len(arr) %2 == 1 else 1
    for i in range(idx, len(arr), 2):
        arr[i] = arr[i] + n
    return arr