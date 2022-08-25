import sys
from collections import deque
N = int(sys.stdin.readline().strip())
draw = [ sys.stdin.readline().strip() for _ in range(N) ]

dy = [0,1,0,-1]
dx = [1,0,-1,0]

people = [0,0]

visited = [[False] * N  for _ in range(N)]

def isMove(y: int , x:int, start_color:str, normal: int) -> bool: 
    if 0 <= y < N and 0 <= x < N:
        if visited[y][x] == False:
            if normal == 0:
                if draw[y][x] == start_color:
                    return True
            else:
                if draw[y][x] == start_color:
                    return True
                elif start_color == "R" and draw[y][x] == "G":
                    return True
                elif start_color == "G" and draw[y][x] == "R":
                    return True
    return False    

for p in range(2):
    for i in range(N):
        for j in range(N):
            if visited[i][j] == False:
                bfs = deque()
                bfs.append([i,j])
                visited[i][j] = True
                start_color = draw[i][j]
                while len(bfs) != 0:
                    y , x = bfs.pop()
                    for d in range(4):
                        if isMove(y + dy[d], x + dx[d], start_color, p):
                            visited[y + dy[d]][x + dx[d]] = True
                            bfs.append([y + dy[d], x + dx[d]])
                people[p] +=1
    visited = [[False] * N  for _ in range(N)]
print(f"{people[0]} {people[1]}")