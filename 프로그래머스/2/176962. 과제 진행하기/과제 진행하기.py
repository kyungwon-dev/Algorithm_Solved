from collections import deque
def time_to_minute(x):
    x = x.split(':')
    return int(x[0]) * 60 + int(x[1])
def solution(plans):
    answer = []
    plan_dict = {plan[0]:[time_to_minute(plan[1]),int(plan[2])] for plan in plans}
    length = len(plan_dict.keys())
    plan_dict = sorted(plan_dict.items(), key=lambda x : x[1][0])
    
    dq = deque(plan_dict)
    print(dq)
    processing_dq = deque([])
    for i in range(length):
        f = dq.popleft()
        if not dq:
            answer.append(f[0])
            break  
        if f[1][0] > dq[0][1][0]:
            answer.append(f[0])
            
        elif f[1][0] + f[1][1] > dq[0][1][0] :
            f[1][1] = f[1][1] - (dq[0][1][0] - f[1][0])
            processing_dq.append(f)
        else:
            answer.append(f[0])
            time = dq[0][1][0] - (f[1][0] + f[1][1])
            while time > 0 and processing_dq:
                p = processing_dq.pop()
                if time >= p[1][1]:
                    time -= p[1][1]
                    answer.append(p[0])
                else:
                    p[1][1] -= time
                    time = 0
                    processing_dq.append(p)
            
    
    while processing_dq:
        answer.append(processing_dq.pop()[0])
    
        
    return answer