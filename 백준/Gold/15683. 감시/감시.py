from itertools import product
from timeit import repeat
class CCTV():
    def __init__(self, y, x, num) -> None:
        self.y = y
        self.x = x
        self.num = num
        self.dir = 0
    def __str__(self) -> str:
        return f"{self.y} | {self.x} | {self.num} | {self.dir}"

N , M = map(int , input().split())
office = [ list(map(int, input().split())) for _ in range(N)]
dy = [-1,0,1,0]
dx = [0,1,0,-1]
cctv_direction = {
    1 : ((0,),(1,),(2,),(3,)),
    2 : ((0,2),(1,3)),
    3 : ((0,1),(1,2),(2,3),(3,0)),
    4 : ((0,1,2),(1,2,3),(2,3,0),(3,0,1)),
    5 : ((0,1,2,3),)
}
cctv_locate = []
cctv_simul = []
total_empty = 0

for i in range(N):
    for j in range(M):
        if 0 < office[i][j] < 6:
            cctv = CCTV(i,j,office[i][j])
            cctv_locate.append(cctv)
            cctv_simul.append( [i for i in range(len(cctv_direction[office[i][j]]))] )
cctv_simul = list(product(*cctv_simul))
answer = N*M
for s in cctv_simul:
    sub_ans = 0
    tmp_office = []
    for i in range(len(office)):
        tmp_office.append(office[i][:])
    for i in range(len(cctv_locate)):
        cctv_locate[i].dir = s[i]
        
        # simul
        for d in cctv_direction[cctv_locate[i].num][cctv_locate[i].dir]:
            y, x = cctv_locate[i].y , cctv_locate[i].x
            while True:
                sy = y + dy[d]
                sx = x + dx[d]
                if (0 <= sx < M and 0 <= sy < N) and (tmp_office[sy][sx] != 6):
                    tmp_office[sy][sx] = -1
                else:
                    break
                y , x  = sy, sx
    for i in range(N):
        for j in range(M):
            if tmp_office[i][j] == 0:
                sub_ans +=1
    answer = min(answer , sub_ans)
print(answer)
