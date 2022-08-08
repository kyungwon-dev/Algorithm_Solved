import sys

n, k = map(int, sys.stdin.readline().strip().split())
# 이진 탐색    
nums = sorted([ int(sys.stdin.readline().strip()) for _ in range(n)])
lp , rp = 1, nums[-1]
while lp <= rp:
    mid = (lp+rp) // 2
    cnt = sum(list(map(lambda x : x//mid , nums )))
    if cnt >= k:
        lp = mid+1
    else:
        rp = mid-1
print(f"{(lp + rp) // 2}")


