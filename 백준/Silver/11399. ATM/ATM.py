import sys
N = int(sys.stdin.readline().strip())
peoples = list(map(int, sys.stdin.readline().strip().split()))
peoples.sort()
answer = 0
for i in range(N):
    answer += sum(peoples[0:i+1])
print(answer)