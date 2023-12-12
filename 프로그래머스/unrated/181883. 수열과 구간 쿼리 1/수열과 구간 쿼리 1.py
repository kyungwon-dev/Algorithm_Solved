def solution(arr, queries):
    answer = []
    for i,j in queries:
        for z in range(i,j+1,1):
            arr[z] += 1
    return arr