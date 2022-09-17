import sys

N, M ,B = map(int, sys.stdin.readline().strip().split())
grounds = [ list(map(int, sys.stdin.readline().strip().split())) for _ in range(N) ]

answer_time, answer_height = sys.maxsize , 0
height = min ( min([ min(grounds[i]) for i in range(N)]), 256)
max_height = min ( ( B + sum([ sum(grounds[i]) for i in range(N)]) ) // ( N*M), 256)

while height <= max_height:
    plus, minus = 0, 0
    time = 0
    bag = B
    
    for ground in grounds:
        for g in ground:
            if g > height:
                minus+= (g - height)
            else:
                plus +=(height - g)
    
    if minus + B >= plus:
        time = plus + (minus * 2)
        if time <= answer_time:
            answer_time = time
            answer_height = height
    height +=1
print(answer_time, answer_height, sep=" ")