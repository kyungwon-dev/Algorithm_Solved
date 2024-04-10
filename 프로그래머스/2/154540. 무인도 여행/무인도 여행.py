from collections import deque

def solution(maps):
    # Flood Fill 알고리즘 사용 -> BFS
    answer = []
    dy = [0,1,0,-1]
    dx = [1,0,-1,0]
    dq = deque([])
    check_maps = [ [False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if maps[i][j] != 'X' and check_maps[i][j] == False:
                score = 0
                dq.append((i,j))
                check_maps[i][j] = True
                
                while dq:
                    y , x = dq.popleft()    
                    score += int(maps[y][x])
                    for d in range(4):
                        sy , sx = y + dy[d], x + dx[d]
                        if not (0 <= sy < len(maps) and 0 <= sx < len(maps[0])):
                            continue
                        if check_maps[sy][sx] or maps[sy][sx] == 'X':
                            continue
                        
                        dq.append([sy, sx])
                        check_maps[sy][sx] = True
                answer.append(score)
    if not answer:
        answer.append(-1)
    else:
        answer.sort()
    print(check_maps)
    return answer