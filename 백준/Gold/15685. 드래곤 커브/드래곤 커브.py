MAX = 101
boards = [[False for _ in range(MAX)] for _ in range(MAX)]
dy = [0,-1,0,1]
dx = [1,0,-1,0]
N = int(input())
for i in range(N):
    x, y, d, g = map(int, input().split())
    boards[y][x] = True
    move = [d]
    for j in range(g):
        # duplicate
        tmp = move[:]
        # backward
        tmp = list(map(lambda x : (x+2) % 4, tmp))
        # rotate
        tmp = list(map(lambda x : x-1 if x-1 >= 0 else 3, tmp))
        # reverse
        tmp.reverse()
        # append
        move.extend(tmp)
    
    # move to board
    for m in move:
        y = y + dy[m]
        x = x + dx[m]
        boards[y][x] = True
cnt = 0
for i in range(MAX):
    for j in range(MAX):
        if boards[i][j] and boards[i-1][j] and boards[i][j-1] and boards[i-1][j-1]:
            cnt+=1
print(cnt)