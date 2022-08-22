import sys

N = sys.stdin.readline().strip()
rooms = map(int, sys.stdin.readline().strip().split())
mj_director, mn_director = map(int , sys.stdin.readline().strip().split())
answer = 0
for room in rooms:
    room -= mj_director
    answer += 1
    if room > 0:
        answer = answer + room // mn_director + (0 if room % mn_director == 0 else 1)
        
print(answer)