import sys
from collections import deque
T = int(sys.stdin.readline().strip())

dy = [0,1,0,-1]
dx = [1,0,-1,0]

for testcase in range(T):
    M, N, K = map(int, sys.stdin.readline().strip().split())
    grounds = [ [ 0 for _ in range(M)] for _ in range(N) ]
    visited = [ [ False for _ in range(M)] for _ in range(N) ]
    answer = 0
    for i in range(K):
        x, y = map(int, sys.stdin.readline().strip().split())
        grounds[y][x] = 1
    for i in range(N):
        for j in range(M):
            if grounds[i][j] == 1 and visited[i][j] == False:
                q  = deque([])
                q.append((i,j))
                visited[i][j] = True
                while q:
                    y, x = q.popleft()
                    for d in range(4):
                        sy = y + dy[d]
                        sx = x + dx[d]
                        if 0 <= sy < N and 0 <= sx < M and visited[sy][sx] == False and grounds[sy][sx] == 1:
                            q.append((sy,sx))
                            visited[sy][sx] = True
                answer +=1
    print(answer)