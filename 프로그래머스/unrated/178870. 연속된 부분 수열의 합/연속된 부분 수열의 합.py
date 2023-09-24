from collections import deque
def solution(sequence, k):
    answer = []
    sum = 0
    candidate = [0,0]
    nums = deque([])
    for i in range(len(sequence)):
        sum = sum + sequence[i]
        nums.append(sequence[i])
        candidate[1] = i
        
        if sum == k:
            start, end = candidate
            answer.append([start,end, end-start])
        elif sum < k:
            pass
        else:
            while sum > k:
                num = nums.popleft()
                candidate[0] += 1
                sum = sum - num
            if sum == k:
                # print(candidate)
                start, end = candidate
                answer.append([start,end, end-start])
                # print(answer)
        
    answer.sort(key = lambda x : (x[2], x[0]))
    return answer[0][:2]