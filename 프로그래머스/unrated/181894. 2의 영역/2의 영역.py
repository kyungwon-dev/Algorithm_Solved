def solution(arr):
    minIndex , maxIndex = 100000, -100000
    answer = []
    for i in range(len(arr)):
        if arr[i] == 2:
            minIndex = min(minIndex, i)
            maxIndex = max(maxIndex, i)
        
    while minIndex <= maxIndex:
        answer.append(arr[minIndex])
        minIndex +=1
    
    if not answer:
        answer.append(-1)
    return answer