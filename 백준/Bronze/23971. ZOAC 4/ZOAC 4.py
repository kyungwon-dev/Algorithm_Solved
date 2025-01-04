import sys
input = sys.stdin.readline

# time limit = 1sec, memory limit = 512mb
# max_input = 50,000(h,w,n,m)
# case 1. brute-force
# time_compliex = 50000 * 50000 = 25 * 10^8 > 1sec (10^8)

# case 2. 규칙 찾아서 개수 count
h, w, n, m = map(int, input().strip().split())


y = (h - 1) // (n+1) + 1
x = (w - 1) // (m+1) + 1
print(y*x)