import math
def solution(k, d):
    answer = 0
    for i in range(0, d+1, k):
        if (d**2 - i**2) >= 0 :
            answer += int(math.sqrt(d**2 - i**2)) // k + 1
        else:
            continue
        # print(int(math.sqrt(d**2 - i**2)) // k + 1)
        # if 
        # for j in range(0, d+1, k):
        #     if (i**2) + (j**2) <= (d**2):
        #         answer+=1
        #     else:
        #         break
    return answer