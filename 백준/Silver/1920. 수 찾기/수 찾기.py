import sys

n = int(sys.stdin.readline().rstrip())
n_nums = {v:True for v in sys.stdin.readline().rstrip().split()}
m = int(sys.stdin.readline().rstrip())
m_nums = sys.stdin.readline().rstrip().split()
for num in m_nums:
    try:
        if n_nums[num]:
            print(1)
    except KeyError:
        print(0)

