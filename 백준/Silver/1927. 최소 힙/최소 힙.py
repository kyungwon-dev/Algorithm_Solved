import sys
import heapq
N = int(sys.stdin.readline().strip())
q = []
for i in range(N):
    cmd = int(sys.stdin.readline().strip())
    if cmd == 0:
        if not q:
            print(0)
        else:
            print(heapq.heappop(q))
    else:
        heapq.heappush(q,cmd)