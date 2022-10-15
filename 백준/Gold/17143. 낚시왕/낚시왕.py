R, C , M = map(int, input().split())
fising_rounge = [[[-1,0,0] for _ in range(C)] for _ in range(R)]
dr = [-1,1,0,0]
dc = [0,0,1,-1]
dr_arr = [
    [i for i in range(R)] + [i for i in range(R-2, 0, -1)],
    [i for i in range(R-1, 0-1, -1)] + [i for i in range(1, R-1)],
    [i for i in range(C-1, 0-1, -1)] + [i for i in range(1, C-1)],
    [i for i in range(C)] + [i for i in range(C-2, 0, -1)]
]
d_arr = [
    [0] + [1 for _ in range(R-1)] + [0 for _ in range(R-2)],
    [1] + [0 for _ in range(R-1)] + [1 for _ in range(R-2)],
    [2] + [3 for _ in range(C-1)] + [2 for _ in range(C-2)],
    [3] + [2 for _ in range(C-1)] + [3 for _ in range(C-2)]
]
fisher = -1
for i in range(M):
    r, c, s, d, z = map(int, input().split())
    if fising_rounge[r-1][c-1][0] == -1:
        fising_rounge[r-1][c-1] = [s, d-1, z]
    else:
        if fising_rounge[r-1][c-1][2] < z:
            fising_rounge[r-1][c-1] = [s, d-1, z]
        else:
            pass
             
answer = 0
if M != 0 :
    if R==1 and C==1 :
        answer = fising_rounge[0][0][2]
    else:
        
        for i in range(C):
            # fisher move
            fisher +=1
            
            # fish
            for j in range(R):
                if fising_rounge[j][fisher][0] != -1:
                    answer += fising_rounge[j][fisher][2]
                    fising_rounge[j][fisher] = [-1,0,0]
                    break
            
            move_rounge = [[[-1,0,0] for _ in range(C)] for _ in range(R)]
            
            # shark move
            for i in range(R):
                for j in range(C):
                    if fising_rounge[i][j][0] != -1:        
                        s, d , z= fising_rounge[i][j]
                        tr = i + s * dr[d]
                        tc = j + s * dc[d]
                        if 0<= tr < R and 0 <= tc < C:
                            if move_rounge[tr][tc][0] == -1:
                                move_rounge[tr][tc] = [s, d, z]
                            else:
                                if move_rounge[tr][tc][2] < z:
                                    move_rounge[tr][tc] = [s, d, z]                                    
                        else:
                            ds = 0
                            if d == 0:
                                ds = s - abs(i - 0)
                                tr = dr_arr[d][ds % len(dr_arr[d])]
                                d = d_arr[d][ds % len(dr_arr[d])]
                            elif d == 1:
                                ds = s - abs(R - i -1)
                                tr = dr_arr[d][ds % len(dr_arr[d])]
                                d = d_arr[d][ds % len(dr_arr[d])]
                            elif d == 2:
                                ds = s - abs(C -j -1)
                                tc = dr_arr[d][ds % len(dr_arr[d])]
                                d = d_arr[d][ds % len(dr_arr[d])]
                            else:
                                ds = s - abs(j - 0)
                                tc = dr_arr[d][ds % len(dr_arr[d])]
                                d = d_arr[d][ds % len(dr_arr[d])]
                            if move_rounge[tr][tc][0] == -1:
                                move_rounge[tr][tc] = [s, d, z]
                            else:
                                if move_rounge[tr][tc][2] < z:
                                    move_rounge[tr][tc] = [s, d, z]
                                else:
                                    continue
            for i in range(R):
                for j in range(C):
                    fising_rounge[i][j] = move_rounge[i][j]
            

print(answer)