from collections import deque

def solution(queue1, queue2):
    queue1 , queue2 = deque(queue1), deque(queue2)
    q1_sum , q2_sum = sum(queue1) , sum(queue2)    
    total_sum = q1_sum + q2_sum
    answer = 0
    
    # 예외조건
    if total_sum %2 == 1:
        return -1
    
    if q1_sum == q2_sum:
        return answer
    
    while q1_sum != q2_sum:
        if q1_sum > q2_sum :
            num = queue1.popleft()
            if num > ( (q1_sum + q2_sum) / 2 ):
                return -1
            queue2.append(num)
            q1_sum -= num
            q2_sum += num
        else:
            num = queue2.popleft()
            if num > ( (q1_sum + q2_sum) / 2 ):
                return -1
            queue1.append(num)
            q2_sum -= num
            q1_sum += num
        answer +=1
        
        if answer >= 600000:
            return -1
    return answer