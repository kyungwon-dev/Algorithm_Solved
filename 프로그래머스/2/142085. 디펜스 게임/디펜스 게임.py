import heapq
def solution(n, k, enemy):
    answer = 0
    kill = []    
    if k >= len(enemy):
        return len(enemy)
    for i in range(0, len(enemy)):
        heapq.heappush(kill, enemy[i])
        if len(kill) > k:
            minimum = heapq.heappop(kill)
            n -= minimum
            if n < 0:
                return answer
                
        answer+=1
    return answer