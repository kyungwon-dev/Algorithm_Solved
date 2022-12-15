import heapq

def solution(A, B):
    answer = 0
    A, B = [-i for i in A], [-i for i in B] 

    heapq.heapify(A)
    heapq.heapify(B)
    
    while A and B:
        a = -heapq.heappop(A)
        b = -heapq.heappop(B)
        if b > a:
            answer+=1
        else:
            heapq.heappush(B, -b)
            
    return answer