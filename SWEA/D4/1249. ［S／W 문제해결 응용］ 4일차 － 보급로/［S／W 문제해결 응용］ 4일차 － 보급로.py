from collections import deque
import heapq

max_value = 1000000
dr = [0,1,0,-1]
dc = [1,0,-1,0]
testcase = int(input().strip())
for t in range(testcase):
    n = int(input().strip())
    visited = [ [max_value for _ in range(n)] for _ in range(n)]
    
    def is_move(r,c):
        if 0<=r<n and 0<=c<n:
            return True
        return False
    boards = [ input().strip() for _ in range(n)]
    visited[0][0] = int(boards[0][0])
    q = []
    heapq.heappush(q, (visited[0][0], 0, 0))
    while q:    
        v, r, c = heapq.heappop(q)
        for d in range(4):
            tr = r + dr[d]
            tc = c + dc[d]
            if is_move(tr, tc):
                if visited[tr][tc] != max_value:
                    continue
                min_v = max_value
                for tt in range(4):
                    cr = tr + dr[tt]
                    cc = tc + dc[tt]
                    if is_move(cr,cc):
                        min_v = min(min_v, visited[cr][cc])

                # q.append([tr,tc])           
                visited[tr][tc] = min(min_v, visited[tr][tc]) + int(boards[tr][tc])
                heapq.heappush(q, (visited[tr][tc], tr, tc))
                    
    print(f"#{t+1} {visited[-1][-1]}")