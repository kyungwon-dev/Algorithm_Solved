import sys
N = int(sys.stdin.readline().strip())
nums = list(map(int , sys.stdin.readline().strip().split()))
answer = [-1]
s = [nums[-1]]
for i in range(N-2, 0 -1, -1):
    if s[-1] > nums[i]:
        answer.append(s[-1])
    else:
        while s and s[-1] <= nums[i]:
            s.pop()
        if not s:
            answer.append(-1)
        else:
            answer.append(s[-1])
    s.append(nums[i])
answer.reverse()
print(" ".join(map(str, answer)))