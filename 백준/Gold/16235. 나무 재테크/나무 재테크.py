from typing import Deque

N, M ,K = map(int, input().split())

ground = [ [Deque() for _ in range(N)] for _ in range(N)]
farm = [ [5 for _ in range(N)] for _ in range(N)]
fertilizer = [list(map(int, input().split())) for _ in range(N)]

dr = [-1,-1,-1,0,0,1,1,1]
dc = [-1,0,1,-1,1,-1,0,1]

for i in range(M):
    r, c ,age = map(int, input().split())
    r, c = r-1, c-1
    ground[r][c].append(age)
while K > 0:    
    # spring , summer    
    for i in range(N):
        for j in range(N):
            trees = len(ground[i][j])
            for t in range(trees):
                if farm[i][j] >= ground[i][j][t]:
                    farm[i][j] -= ground[i][j][t]
                    ground[i][j][t] +=1
                else:
                    for k in range(t, trees):
                        farm[i][j] += (ground[i][j].pop() // 2)
                    break
                    
    # fall, winter
    
    for i in range(N):
        for j in range(N):
            for tree in ground[i][j]:
                if tree % 5 == 0:
                    for d in range(8):
                        tr = i + dr[d]
                        tc = j + dc[d]
                        if 0<= tr < N and 0<= tc < N:
                            ground[tr][tc].appendleft(1)
                    
            farm[i][j] += fertilizer[i][j]
    K-=1
answer = 0
for i in range(N):
    for j in range(N):
        answer += len(ground[i][j])
print(answer)