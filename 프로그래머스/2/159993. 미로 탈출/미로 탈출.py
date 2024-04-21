from collections import deque


def solution(maps):
    answer = 0
    visited_maps = [ [-1 for _ in range(len(maps[0]))] for _ in range(len(maps))]
    start, end = [], []
    dy = [0,1,0,-1]
    dx = [1,0,-1,0]
    for i in range(len(maps)):
        for j in range(len(maps[i])):
            if maps[i][j] == "S":
                start = [i,j]
            if maps[i][j] == "E":
                end = [i,j]
            if maps[i][j] == "L":
                # BFS 시작
                visited_maps[i][j] = 0 # 초기 위치 방문처리
                bfs = deque([]) # deque 생성
                bfs.append([i,j]) # 레버 위치 지정
                while bfs:
                    y, x = bfs.popleft()
                    for d in range(4): # 우하좌상
                        sy , sx = y +dy[d], x + dx[d]
                        # 배열을 넘어가는 경우
                        if ( 0 <= sy < len(maps) ) and ( 0 <= sx < len(maps[0])): 
                            # 이동하는 지점이 이미 방문했었거나(-1), 벽이 아닌 경우 (SELO) 통과
                            if (visited_maps[sy][sx] == -1) and (maps[sy][sx] != "X"):
                                bfs.append([sy, sx])
                                visited_maps[sy][sx] = visited_maps[y][x] + 1
    # print(visited_maps)
    if (visited_maps[start[0]][start[1]] == -1) or (visited_maps[end[0]][end[1]] == -1):
        return -1
    
    answer = visited_maps[start[0]][start[1]] + visited_maps[end[0]][end[1]]
    return answer