# 2 ,6 change. 0 -> answer
wheels = [list(input()) for _ in range(4)]
K = int(input())
def rotate(dir:int, wheel_idx:int) -> list:
    tmp = []
    if dir == -1:
        for i in range(1, 8):
            tmp.append(wheels[wheel_idx][i])
        tmp.append(wheels[wheel_idx][0])
    elif dir == 1:
        tmp.append(wheels[wheel_idx][7])
        for i in range(0, 7):
            tmp.append(wheels[wheel_idx][i])
    else:
        tmp = wheels[wheel_idx][:]
    return tmp
for i in range(K):
    wheel_idx , direction = map(int, input().split())
    wheel_idx-=1
    # move_wheel
    moves = [False for _ in range(4)]
    direcs = [0,0,0,0]
    moves[wheel_idx] = True
    direcs[wheel_idx] = direction
    # magnatic
    # right
    chain_direction = direction
    for i in range(wheel_idx, 3):
        if wheels[i][2] != wheels[i+1][6]:            
            chain_direction *= -1
            moves[i+1] = True
            direcs[i+1] = chain_direction
        else:
            break
    # left
    chain_direction = direction
    for i in range(wheel_idx, 0, -1):
        if wheels[i][6] != wheels[i-1][2]:
            chain_direction *= -1
            moves[i-1] = True
            direcs[i-1] = chain_direction
        else:
            break
    
    for i in range(4):
        if moves[i]:
            wheels[i] = rotate(direcs[i], i)
        
score = 0
for i in range(len(wheels)):
    if wheels[i][0] == '1':
        score += (2**i)
print(score)