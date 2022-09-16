import sys
import itertools
import copy

N, M, H = map(int, sys.stdin.readline().split())

dy = [0,1,0]
dx = [-1,0,1]

radder = [ [0 for _ in range(N)] for _ in range(H+2) ]
for i in range(H+2):
    for j in range(N):
        if i==0 or i == H+1:
            radder[i][j] = j+1

for i in range(M):
    r, c = map(int, sys.stdin.readline().split())
    radder[r][c] = i+1
    radder[r][c-1] = i+1

candidates = []
for i in range(1, len(radder)-1):
    for j in range(N-1):
        if radder[i][j] == 0 and radder[i][j+1] == 0:
            candidates.append((i,j))
        
tries = 0

while tries < 4:
    # 모든 경우의 수 
    try_candidates = list(itertools.combinations(candidates,tries))
    
    for try_candidate in try_candidates:
        is_build = True
        tmp_radder = radder
        idx=1
        for y,x in try_candidate:
            if tmp_radder[y][x] == 0 and tmp_radder[y][x+1] == 0:
                tmp_radder[y][x] = M + idx
                tmp_radder[y][x+1] = M + idx
                idx+=1
            else:
                is_build = False
                break
        if is_build == False:
            for y,x in try_candidate:
                tmp_radder[y][x] = 0
                tmp_radder[y][x+1] = 0
            continue
        is_mynum = True
        for num in range(N):    
            y, x = 1, num
            while is_mynum:
                if y == H+1:
                    if tmp_radder[y][x] != tmp_radder[0][num]:
                        is_mynum = False
                    break
                if tmp_radder[y][x] != 0:
                    if 0< x and tmp_radder[y][x-1] == tmp_radder[y][x]:
                        x -=1
                    elif x <= (N-1) and tmp_radder[y][x+1] == tmp_radder[y][x]:
                        x +=1
                y +=1
            if is_mynum == False:
                break
        
        if is_mynum:
            print(tries)
            exit(0)
        for y,x in try_candidate:
            tmp_radder[y][x] = 0
            tmp_radder[y][x+1] = 0
    tries+=1
    
print("-1")
    

