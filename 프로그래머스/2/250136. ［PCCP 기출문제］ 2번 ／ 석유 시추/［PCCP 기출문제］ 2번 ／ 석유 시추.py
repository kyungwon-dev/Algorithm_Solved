from collections import deque
def solution(land):
    answer = -1
    land_index = 0
    land_sum = 0
    oil_land = [[-1 for _ in range(len(land[0]))] for _ in range(len(land))]
    oil_land_dict = {}
    dy, dx = [0,1,0,-1], [1,0,-1,0] # 우하좌상
    # print(oil_land)
    for i in range(len(land)):
        for j in range(len(land[0])):
            if land[i][j] == 1 and oil_land[i][j] == -1:
                land_sum =1
                dq = deque([])
                dq.append((i,j))
                oil_land[i][j] = land_index
                land_sum +=1
                while dq:
                    y, x = dq.popleft()
                    for d in range(4):
                        sy, sx = y + dy[d], x + dx[d]
                        if sy < 0 or sy >= len(land) or sx < 0 or sx >= len(land[0]):
                            continue
                        if land[sy][sx] == 1 and oil_land[sy][sx] == -1:
                            dq.append((sy,sx))
                            oil_land[sy][sx] = land_index
                            land_sum+=1
                
                oil_land_dict[land_index] = land_sum-1
                land_index+=1
                
    # print(oil_land)
    # print(oil_land_dict)
    for i in range(len(land[0])):
        pipe = []
        for j in range(len(land)):
            if oil_land[j][i] != -1:
                pipe.append(oil_land[j][i])
        pipe = set(pipe)
        sub_sum = sum([oil_land_dict[k] for k in pipe])
        # print(i, sub_sum)
        answer = max(sub_sum, answer)
    return answer