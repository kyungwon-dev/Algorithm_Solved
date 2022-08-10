from collections import deque
import sys

p_dirY = [0, 1, 0, -1]
p_dirX = [1, 0, -1, 0]
n_dirY = [1, 0, -1, 0]
n_dirX = [0, 1, 0, -1]

T = int(sys.stdin.readline().strip())

for i in range(T):
    N, D = map(int, sys.stdin.readline().strip().split())
    nums = [list(sys.stdin.readline().strip().split()) for _ in range(N)]
    dirY = []
    dirX = []
    if -360 < D < 0:
        dirY = n_dirY
        dirX = n_dirX
    elif 0 < D < 360:
        dirY = p_dirY
        dirX = p_dirX
    else:
        for num in nums:
            print(f"{' '.join(num)}")
        continue
    
    dist =  abs(D // 45)
    for i in range(1, N - (N//2)):
        # 시작점
        y, x = [N//2 - i, N//2 - i]
        q = deque()
        
        for dy,dx in zip(dirY, dirX):
            while True:
                yy = y + (dy*i)
                xx = x + (dx*i)
                if N//2 - i <= yy <= N//2+i and N//2 - i <= xx <= N//2+i:
                    q.append(nums[yy][xx])
                    y = yy
                    x = xx
                else:
                    break
            
        for _ in range(dist):
            q.appendleft(q.pop())
        
        for dy,dx in zip(dirY, dirX):
            while True:
                yy = y + (dy*i)
                xx = x + (dx*i)
                if N//2 - i <= yy <= N//2+i and N//2 - i <= xx <= N//2+i:
                    nums[yy][xx] = q.popleft()
                    y = yy
                    x = xx
                else:
                    break
    for num in nums:
        print(f"{' '.join(num)}")
