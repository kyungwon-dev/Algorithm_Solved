import sys
class Dice():
    def __init__(self) -> None:
        self.l = 0 # 좌
        self.r = 0 # 우
        self.u = 0 # 위
        self.d = 0 # 아
        self.o = 0 # 윗면
        self.b = 0 # 아랫면
    def rotate_dice(self, m:int)->None:
        if m==0:
            self.l, self.o, self.r, self.b = self.b, self.l, self.o, self.r
        elif m==1:
            self.l, self.o, self.r, self.b = self.o, self.r, self.b, self.l
        elif m==2:
            self.u, self.o, self.d, self.b = self.o, self.d, self.b, self.u
        else:
            self.u, self.o, self.d, self.b = self.b, self.u, self.o, self.d
        
n, m, y, x, k = map(int, sys.stdin.readline().strip().split())
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
boards = [] 
for i in range(n):
    boards.append(list(map(int, sys.stdin.readline().strip().split())))
commands = list(map(int, sys.stdin.readline().strip().split()))
dice = Dice()
def is_move(sy:int, sx:int)-> bool:
    if 0 <= sy < n and 0 <= sx < m:
        return True
    return False
for command in commands:
    sy = y + dy[command-1]
    sx = x + dx[command-1]
    if is_move(sy,sx):
        y , x = sy, sx
        dice.rotate_dice(command-1)        
        if boards[y][x] == 0:
            boards[y][x] = dice.b
        else:
            dice.b = boards[y][x]
            boards[y][x] = 0
        print(dice.o)