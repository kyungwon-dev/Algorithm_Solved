import math
def solution(r1, r2):
    answer = 0
    for i in range(0, r2+1, 1): # r2 점
        answer += math.floor(math.sqrt(r2**2 - i**2))
        
    for i in range(0, r1, 1):
        answer -= math.ceil(math.sqrt(r1**2 - i**2))
        answer += 1
    return answer*4