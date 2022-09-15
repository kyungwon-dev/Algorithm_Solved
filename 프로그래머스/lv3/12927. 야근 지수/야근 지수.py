import heapq
def solution(n, works):
    answer = 0
    if n < sum(works):
        min_value = -min(works)
        works = [-i for i in works]
        heapq.heapify(works)
        while n > 0:
            value = heapq.heappop(works)
            if value == min_value:
                heapq.heappush(works, value)
                break
            heapq.heappush(works, value+1)
            n-=1
        q, d = divmod(n, len(works))
        for i in range(len(works)):
            works[i] = works[i] + q
            if d>0:
                works[i] +=1
                d-=1
        for work in works:
            answer += (work ** 2)
        
    
    return answer