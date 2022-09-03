import sys

class Robot():
    def __init__(self, y:int, x:int ,d:int):
        self.y = y
        self.x = x
        self.d = d
dy = [-1,0,1,0]
dx = [0,1,0,-1]
answer = 0

#input
n, m = map(int, sys.stdin.readline().strip().split())
robot = Robot(*map(int, sys.stdin.readline().strip().split()))

def isMpve(y:int, x:int, d:int):
    
    dd = 3 if d==0 else d-1
    yy, xx = y + dy[dd] , x + dx[dd]
    if 0<= yy < n and 0 <= xx < m and room[yy][xx] == 0:
        return True
    return False

# dirty : 0, wall : 1, clean : 2
room = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
trial = 0
while True:
    # step 1
    if room[robot.y][robot.x] == 0:
        room[robot.y][robot.x] = 2
        answer +=1
        trial = 0
        
    # step 2
    if isMpve(robot.y, robot.x, robot.d):
        robot.d = 3 if robot.d==0 else robot.d-1
        robot.y += dy[robot.d]
        robot.x += dx[robot.d]
        trial = 0
    else:
        if trial == 4:
            yy = robot.y - dy[robot.d]
            xx = robot.x - dx[robot.d]
            trial = 0
            if 0<= yy < n and 0 <= xx < m and room[yy][xx] != 1:
                robot.y = yy
                robot.x = xx
                continue
            else:
                # print(yy, xx)
                break
        else:
            robot.d = 3 if robot.d==0 else robot.d-1
            trial+=1            
print(answer)
# print(room)


