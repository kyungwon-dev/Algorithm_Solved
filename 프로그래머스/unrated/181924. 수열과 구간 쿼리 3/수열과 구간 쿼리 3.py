def solution(arr, queries):
    
    for q in queries:
        prev_, next_ = q
        tmp = arr[prev_]
        arr[prev_] = arr[next_]
        arr[next_] = tmp
    return arr