import sys
from collections import deque

class Snake():
    def __init__(self) -> None:
        self.direction = 1
        self.body = deque([[0,0]])

time_max = 10000
N = int(sys.stdin.readline())
K = int(sys.stdin.readline())
# directions
dy = [-1,0,1,0]
dx = [0,1,0,-1]
# board spec
# 0 : empty , -1 : wall, 1 : apple, 2 : snake

board = [ [0 for _ in range(N)] for _ in range(N) ]
# for i in range(N):
#     for j in range(N):
#         if i==0 or j==0 or i==N-1 or j==N-1:
#             board[i][j] = -1

# apple
for i in range(K):
    r, c = map(int, sys.stdin.readline().split())
    board[r-1][c-1] = 1
# snake
board[0][0] = 2
snake = Snake()

# print(board)

# move_list
L = int(sys.stdin.readline())
move_list = []
for i in range(L):
    second, direction = sys.stdin.readline().split()
    second = int(second)
    if direction == "D":
        direction = 1
    else:
        direction = -1
    move_list.append([second, direction])

answer = 0
while True:
    if move_list:
        if answer == move_list[0][0]:
            snake.direction += move_list[0][1]
            if snake.direction == -1:
                snake.direction = 3
            elif snake.direction == 4:
                snake.direction = 0
            move_list.pop(0)
    
    sd = snake.direction
    sb_y, sb_x = snake.body[0][0] + dy[sd], snake.body[0][1] + dx[sd]
    
    answer +=1
    # body
    if 0 <= sb_y < N and 0 <= sb_x < N:
        if board[sb_y][sb_x] == 1: # apple
            snake.body.appendleft([sb_y, sb_x])
            board[sb_y][sb_x] = 2
            
        elif board[sb_y][sb_x] == 2:
            break
        else:
            # move
            board[sb_y][sb_x] = 2
            board[snake.body[-1][0]][snake.body[-1][1]] = 0
            snake.body.appendleft([sb_y, sb_x])
            snake.body.pop()
    else:
        break

print(answer)