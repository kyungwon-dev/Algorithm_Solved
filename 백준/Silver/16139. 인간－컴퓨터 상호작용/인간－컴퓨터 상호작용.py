import sys
input = sys.stdin.readline

keyboards = input().rstrip()
alpha_sum = [ [0] * 26 for _ in range(len(keyboards) + 1)]

for i in range(1, len(keyboards) + 1):
    key = ord(keyboards[i-1]) - 97
    for j in range(26):
        if j == key:
            alpha_sum[i][j] = alpha_sum[i-1][j] + 1
        else:
            alpha_sum[i][j] = alpha_sum[i-1][j]

q_num = int(input().rstrip())
for i in range(q_num):
    a, l ,r = input().rstrip().split()
    l = int(l)
    r = int(r)
    a = ord(a) - ord("a")
    sys.stdout.write(str(alpha_sum[r+1][a] - alpha_sum[l][a]) + "\n")