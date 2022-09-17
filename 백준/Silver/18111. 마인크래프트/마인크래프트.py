import sys

N, M ,B = map(int, sys.stdin.readline().strip().split())
grounds = [ list(map(int, sys.stdin.readline().strip().split())) for _ in range(N) ]

answer_time, answer_height = sys.maxsize , 0
height = 0

while height <= 256:
    plus, minus = 0, 0
    time = 0
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