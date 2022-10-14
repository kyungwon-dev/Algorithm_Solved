from collections import deque


N , L , R = map(int, input().split())
world = [ list(map(int, input().split())) for _ in range(N)]
dy = [0,1,0,-1]
dx = [1,0,-1,0]
answer = 0
while True:
    boundary = [ [0 for _ in range(N)] for _ in range(N)] # 
    territory = 1
    territory_map = {}
    for i in range(N):
        for j in range(N):
            # 인구이동 존재
            if boundary[i][j] == 0 and \
               ( ( i+1 < N and (L <= abs(world[i][j] - world[i+1][j]) <= R) )  or ( j+1 < N  and (L <= abs(world[i][j] - world[i][j+1]) <= R) ) ):
                q = deque()
                q.append((i,j))
                territory_map[territory] = [world[i][j],1]
                boundary[i][j] = territory
                while q :
                    y, x = q.popleft()
                    for d in range(4):
                        sy = y + dy[d]
                        sx = x + dx[d]
                        if (0 <= sx < N and 0 <= sy < N) and (L <= abs(world[y][x] - world[sy][sx]) <= R) and boundary[sy][sx]==0:
                            boundary[sy][sx] = boundary[y][x]        
                            q.append( (sy,sx))
                            territory_map[territory][0] += world[sy][sx]
                            territory_map[territory][1] += 1
                territory+=1
                    
    for k in territory_map.keys():
        territory_map[k] = territory_map[k][0] // territory_map[k][1]
    
    for i in range(N):
        for j in range(N):
            if boundary[i][j] !=0:
                world[i][j] = territory_map[boundary[i][j]]
    if territory == 1:
        break
    answer+=1
print(answer)