import sys
keyboards = sys.stdin.readline().strip()
alpha_sum = [ [0 for _ in range(26)] for _ in range(len(keyboards))]
minimum = ord('a')
alpha_sum[0][ord(keyboards[0]) - minimum] = 1

for i in range(1, len(alpha_sum)):
    alpha = ord(keyboards[i])
    alpha_sum[i][alpha - minimum] = 1
    for j in range(26):
        alpha_sum[i][j] += alpha_sum[i-1][j]
          
q_num = int(sys.stdin.readline().strip())

for i in range(q_num):
    a, l ,r = sys.stdin.readline().strip().split()
    l , r = map(int, [l, r])
    a = ord(a)
    rs = alpha_sum[r][ a - minimum]
    if l > 0:
        rs -= alpha_sum[l-1][a - minimum ]
    print(rs)