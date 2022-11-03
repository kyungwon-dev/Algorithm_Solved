import sys
sys.setrecursionlimit(10**5)

# input
N = int(sys.stdin.readline().strip())
dist = list(map(int, sys.stdin.readline().strip().split()))
nodes = list(map(int, sys.stdin.readline().strip().split()))

answer = nodes[0] * dist[0]
length = 0
idx = 0
if N == 2:
    answer = nodes[0] * sum(dist)
else:
    for i in range(1, N-1):
        if nodes[idx] <= nodes[i]:
            length += dist[i]
        else:
            answer += (length * nodes[idx])
            length = dist[i]
            idx = i
    answer += (length * nodes[idx])
print(answer)