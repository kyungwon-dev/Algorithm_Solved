def solution(arr):
    answer = -1
    sameCount = 0
    while sameCount != len(arr):
        sameCount = 0
        prev = arr[:]
        for i in range(len(arr)):
            if arr[i] >= 50 and arr[i] % 2 == 0:
                arr[i] = arr[i] // 2
            elif arr[i] < 50 and arr[i] % 2 ==1:
                arr[i] = arr[i] * 2 + 1
            if arr[i] == prev[i]:
                sameCount+=1
        answer +=1
    return answer