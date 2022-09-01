from collections import deque
import sys
N, M = map(int , sys.stdin.readline().strip().split())
nums = deque([i+1 for i in range(N)])
pop_nums = deque(list(map(int , sys.stdin.readline().strip().split())))
cnt = 0
while pop_nums:
    if nums[0] == pop_nums[0]:
        nums[0] = 0
        pop_nums.popleft()
        nums.popleft()
    else:
        idx = nums.index(pop_nums[0])    
        ls, rs = idx, len(nums) - idx
        if ls < rs:
            while nums[0] != pop_nums[0]:
                cnt+=1
                nums.append(nums.popleft())
        else:
            while nums[0] != pop_nums[0]:
                cnt+=1
                nums.appendleft(nums.pop())
    
print(cnt)