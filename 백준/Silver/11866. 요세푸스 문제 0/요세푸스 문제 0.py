import sys
from collections import deque

n, k = map(int, sys.stdin.readline().rstrip().split())
people = deque(map(str, list(range(1,n+1))))
answer = []
idx = 1
while len(people) != 0:
    f = people.popleft()
    if idx % k == 0:
        answer.append(f)
    else:
        people.append(f)
    idx +=1 
print(f"<{', '.join(answer)}>")