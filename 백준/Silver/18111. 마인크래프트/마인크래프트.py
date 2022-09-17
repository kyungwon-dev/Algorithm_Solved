import sys

N, M ,B = map(int, sys.stdin.readline().strip().split())
grounds = [ list(map(int, sys.stdin.readline().strip().split())) for _ in range(N) ]

answer_time, answer_height = sys.maxsize , 0
height_count = [ 0 for _ in range(256 + 1)]
max_height = 0

for ground in grounds:
    for g in ground:
        height_count[g] +=1
        max_height += g


min_height = min( [min(ground) for ground in grounds])
max_height = (max_height + B) // (M * N) 

height = min_height
while height <= max_height:
    plus, minus = 0, 0
    time = 0
    bag = B
    
    for h in range( min_height, min(256+1, 256 + 1)):
        if height < h:
            time += (height_count[h]) * ( h - height) * 2
            bag += (height_count[h]) * ( h - height)
        else:
            time += (height_count[h]) * ( height - h)
            bag -= (height_count[h]) * ( height - h)
    if time <= answer_time and bag >= 0:
        answer_time = time
        answer_height = height
    height +=1
print(answer_time, answer_height, sep=" ")