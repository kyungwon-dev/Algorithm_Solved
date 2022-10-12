import sys
import itertools
from collections import deque

dy = [0,1,0,-1]
dx = [1,0,-1,0]
idx = 0
answer = -1

N , M = map(int, input().split())
lab = [ list(map(int, input().split())) for _ in range(N)]
wall_cand = []
virus = []
clean_place = N*M
for i in range(N):
    for j in range(M):
        if lab[i][j] == 0:
            wall_cand.append((i,j))
            continue
        clean_place -=1
        if lab[i][j] == 2:
            virus.append( (i,j))
clean_place-=3
wall = list(itertools.combinations(wall_cand, 3))
while idx < len(wall):
    sub_answer = clean_place
    install_wall = []
    for i in range(N):
        install_wall.append(lab[i][:])
    for y,x in wall[idx]:
        install_wall[y][x] = 1
    idx+=1
    q = deque()
    q.extend(virus)
    while q:
        y, x = q.popleft()
        for d in range(4):
            sy = y + dy[d]
            sx = x + dx[d]
            if (0<= sy < N and 0 <= sx < M) and (install_wall[sy][sx] == 0):
                q.append((sy,sx))
                install_wall[sy][sx] = 2                
                sub_answer-=1
    answer = max(answer, sub_answer)
    # print(sub_answer)
    # print(install_wall)        
print(answer)        