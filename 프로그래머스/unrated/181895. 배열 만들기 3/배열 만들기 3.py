def solution(arr, intervals):
    answer = sum([arr[i:j+1] for i,j in intervals], [])
    return answer