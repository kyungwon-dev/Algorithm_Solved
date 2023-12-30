def solution(arr):
    answer = []
    i = 1
    while(i < 1024):
        if len(arr) == i:
            return arr
        elif len(arr) < i:
            break
        i = i*2
    tmp = [0] * (i - len(arr))
    arr.extend(tmp)
    return arr