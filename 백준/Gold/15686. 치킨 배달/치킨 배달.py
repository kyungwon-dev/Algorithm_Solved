from itertools import combinations
N, M = map(int, input().split())
city = [ list(map(int, input().split())) for _ in range(N)]
pizza = []
house = []
for i in range(N):
    for j in range(N):
        if city[i][j] == 2:
            pizza.append((i,j))
        elif city[i][j] == 1:
            house.append((i,j))

live_pizza = list(combinations(pizza,M))
answer = 2500
for lp in live_pizza:
    sub_answer = 0
    for h in house:
        min_dist = 1000000
        for p in lp:
            min_dist = min(abs(p[0] - h[0]) +  abs(p[1] - h[1]), min_dist)
        sub_answer += min_dist
    answer = min(sub_answer, answer)
print(answer)