import sys

N , M = map(int, sys.stdin.readline().strip().split())

networks = [ [999999 for _ in range(N)] for _ in range(N)]
for i in range(N):
    networks[i][i] = 0

for i in range(M):
    strt, dst = map(int, sys.stdin.readline().strip().split())
    networks[strt-1][dst-1] = 1
    networks[dst-1][strt-1] = 1

for i in range(N):
    for j in range(N):
        for k in range(N):
            networks[j][k] = min( networks[j][i]+networks[i][k], networks[j][k])
network = [ (sum(networks[i])) for i in range(N)]
min_net = min(network)
for i in range(N):
    if min_net == network[i]:
        print(i+1)
        break