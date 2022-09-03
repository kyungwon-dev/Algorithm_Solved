import sys
n, c = map(int, sys.stdin.readline().strip().split())
houses = []
for i in range(n):
    house = int(sys.stdin.readline().strip())
    houses.append(house)
houses.sort()
lp, rp = 1, houses[-1]-houses[0]
answer = 0
while lp <= rp:
    mid = (lp + rp) // 2
    prev_house = houses[0]
    cnt = 1
    for i in range(1, len(houses)):
        if houses[i] - prev_house >= mid:
            cnt+=1
            prev_house = houses[i]
    
    if cnt >= c:
        answer = max(answer, mid)    
        lp = mid+1
    else:
        rp = mid -1
    
print(answer)