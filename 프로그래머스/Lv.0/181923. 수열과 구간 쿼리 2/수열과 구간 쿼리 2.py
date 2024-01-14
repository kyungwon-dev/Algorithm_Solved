def solution(arr, queries):
    answer = []
    for q1, q2, q3 in queries:
        num = 1000001
        for i in range(q1, q2+1, 1):
            if arr[i] > q3:
                num = min(num, arr[i])
        
        if num == 1000001:
            num = -1
        answer.append(num)
            
    return answer