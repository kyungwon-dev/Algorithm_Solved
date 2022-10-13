from doctest import FAIL_FAST


N, L = map(int, input().split())
route_map = [list(map(int, input().split())) for _ in range(N)]
answer = 0
# 좌 -> 우
for i in range(N):
    base = route_map[i][0]
    base_pos = 0
    is_route = True
    for j in range(1, N):
        if route_map[i][j] == base:
            continue
        else:
            is_route = False
            if abs(route_map[i][j] - base) != 1:
                break
            if route_map[i][j] > base:
                if j - base_pos >= L:
                    base = route_map[i][j]
                    base_pos = j
                    is_route = True
            else:
                if j + L - 1< N:
                    is_construct = True
                    for k in range(j, j+L):
                        if route_map[i][j] != route_map[i][k]:
                            is_construct = False
                            break
                    if is_construct:
                        base_pos = j+L
                        base = route_map[i][j]
                        is_route = True
                        j = j+L
            if is_route == False:
                break
    if is_route:
        answer+=1

# 위 -> 아래
for i in range(N):
    base = route_map[0][i]
    base_pos = 0
    is_route = True
    for j in range(1, N):
        if route_map[j][i] == base:
            continue
        else:
            is_route = False
            if abs(route_map[j][i] - base) != 1:
                break
            if route_map[j][i] > base:
                if j - base_pos >= L:
                    base = route_map[j][i]
                    base_pos = j
                    is_route = True
            else:
                if j + L - 1< N:
                    is_construct = True
                    for k in range(j, j+L):
                        if route_map[j][i] != route_map[k][i]:
                            is_construct = False
                            break
                    if is_construct:
                        base_pos = j+L
                        base = route_map[j][i]
                        is_route = True
                        j = j+L
            if is_route == False:
                break
    if is_route:
        answer+=1

print(answer)
                    
                    
                
        