import sys
from collections import deque
T = int(sys.stdin.readline().strip())
for t in range(T):
    N, M = map(int, sys.stdin.readline().strip().split())
    docs = list(map(int, sys.stdin.readline().strip().split()))
    docs = deque([ [i, v] for i , v in enumerate(docs)])
    loop = 0
    while True:
        
        index, prior = docs.popleft()
        is_print = True
        for i, p in docs:
            if prior < p:
                docs.append([index, prior])
                is_print = False
                break
        if is_print:
            loop+=1
            if index == M:
                print(loop)
                break

