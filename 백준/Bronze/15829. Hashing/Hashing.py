import sys
L = int(sys.stdin.readline().strip())
M = 1234567891
r = [31 ** i for i in range(L)]
a = { chr(ord('a')-1+i) : i for i in range(1, 27, 1)}
strings = list(sys.stdin.readline().strip())
answer = 0
for i, string in enumerate(strings):
    answer += r[i] * a[string]
print(f"{answer % M}")