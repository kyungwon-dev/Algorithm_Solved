import sys
import heapq
n = int(sys.stdin.readline().strip())
left_heqp = []
right_heqp = []
answers = []
for i in range(n):
    num = int(sys.stdin.readline().strip())    
    if len(left_heqp) == len(right_heqp):
        heapq.heappush(left_heqp, (-num, num))
    else:
        heapq.heappush(right_heqp, (num, num))
        
    if right_heqp and left_heqp[0][1] > right_heqp[0][1]:
        l = heapq.heappop(left_heqp)
        r = heapq.heappop(right_heqp)
        heapq.heappush(right_heqp, (-l[0], l[1]))    
        heapq.heappush(left_heqp, (-r[0], r[1]))
    print(left_heqp[0][1])