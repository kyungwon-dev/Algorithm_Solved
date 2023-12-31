def solution(arr, queries):
    for query in queries:
        s, e, k = query
        arr = [arr[i]+1 if i % k ==0 and s<=i<=e else arr[i] for i in range(len(arr))]
    return arr