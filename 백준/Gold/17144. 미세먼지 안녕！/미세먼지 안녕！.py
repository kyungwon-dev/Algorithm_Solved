R, C, T = map(int, input().split())
room = []
air = []
for i in range(R):
    r = list(map(int, input().split()))
    for j in range(C):
        if r[j] == -1:
            air.append( (i,j))
    room.append(r)

dr = [0,1,0,-1]
dc = [1,0,-1,0]
answer = 0
for time in range(T):
    # 확산
    prev_room = [[0 for _ in range(C)] for _ in range(R)]
    for a in air:
        prev_room[a[0]][a[1]] = -1
    for i in range(R):
        for j in range(C):
            if room[i][j] >0:
                middle = room[i][j]
                other = room[i][j]//5
                cnt = 0
                for d in range(4):
                    r = i + dr[d]
                    c = j + dc[d]
                    if (0 <= r < R and 0 <= c < C) and (room[r][c] != -1):
                        prev_room[r][c] += other
                        cnt+=1
                prev_room[i][j] += middle - (other * cnt)
    # 순환
    for i in range(len(air)):
        tmp = air[i]
        store = 0
        if i == 0:
            store = prev_room[tmp[0]][-1]
            # right
            prev_room[tmp[0]] = [-1,0] + prev_room[tmp[0]][1:-1]
            # up
            for j in range(tmp[0]-1, 0, -1):
                store, prev_room[j][-1] = prev_room[j][-1], store            
            # left
            store, prev_room[0] =  prev_room[0][0], prev_room[0][1:] + [store]
            
            # down
            for j in range(1, tmp[0]):
                store, prev_room[j][0] = prev_room[j][0], store
        else:
            store = prev_room[tmp[0]][-1]
            # right
            prev_room[tmp[0]] = [-1,0] + prev_room[tmp[0]][1:-1]
            # down
            for j in range(tmp[0]+1, R-1):
                store, prev_room[j][-1] = prev_room[j][-1], store
            # left
            store, prev_room[-1] =  prev_room[-1][0], prev_room[-1][1:] + [store]
            # up
            for j in range(R-2, tmp[0], -1):
                store, prev_room[j][0] = prev_room[j][0], store            
        prev_room[tmp[0]][tmp[1]] = -1
    answer = 0
    for i in range(R):
        for j in range(C):
            room[i][j] = prev_room[i][j]
            answer += room[i][j]
    # print(room)
print(answer+2)