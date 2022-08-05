import sys
N = int(sys.stdin.readline().rstrip())
A = [int(x) for x in (sys.stdin.readline().rstrip().split())]
B = [int(x) for x in (sys.stdin.readline().rstrip().split())]
B.sort()
A.sort(reverse=True)
answer = sum([x*y for x,y in zip(A,B)])
print(answer)