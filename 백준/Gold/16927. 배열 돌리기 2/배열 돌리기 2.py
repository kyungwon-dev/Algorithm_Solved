from collections import deque
import sys

dirY = [1,0,-1,0]
dirX = [0,1,0,-1]

N, M, R = map(int, sys.stdin.readline().strip().split())
prev = [list(sys.stdin.readline().strip().split()) for _ in range(N)]

for i in range(min(N,M) // 2):
    
    y=x=i
    rotate = deque()
    dir = 0
    while True:
        dy, dx = y + dirY[dir], x + dirX[dir]
        if dy < i or dy >= (N-i) or dx < i or dx >= (M-i):
            dir = (dir + 1) % 4
            continue
        if prev[dy][dx] == '0':
            break
        rotate.append(prev[dy][dx])
        prev[dy][dx] = '0'
        y = dy
        x = dx
    
    for _ in range(R % ((N  - i * 2) * 2 + (M - i * 2) * 2 - 4)):
        rotate.appendleft(rotate.pop())
    
    dir = 0    
    while True:
        dy, dx = y + dirY[dir], x + dirX[dir]
        if dy < i or dy >= (N-i) or dx < i or dx >= (M-i):
            dir = (dir + 1) % 4
            continue
        if prev[dy][dx] !='0':
            break
        prev[dy][dx] = rotate.popleft()
        y = dy
        x = dx
    
for rs in prev:
    print(f"{' '.join(rs)}")
