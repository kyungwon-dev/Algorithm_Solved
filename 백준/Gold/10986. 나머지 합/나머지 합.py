from collections import Counter
import sys

N, M = map(int , sys.stdin.readline().strip().split())
# M = 100
nums = list(map(lambda x : int(x) , sys.stdin.readline().strip().split()))
answer, idx  = 0, 0
acc_nums = [ 0 for _ in range(len(nums))]
for i in range(len(nums)):
    if i == 0:
        acc_nums[i] = nums[i] % M
    else:    
        acc_nums[i] = (acc_nums[i-1] + nums[i]) % M
cnt_acc_sum = Counter(acc_nums)

for k, v in cnt_acc_sum.items():
    answer += int(v * (v-1) / 2)
answer += cnt_acc_sum[0]            
print(answer)
