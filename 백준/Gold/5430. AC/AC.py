from collections import deque
import sys
T = int(sys.stdin.readline().strip())
for testcase in range(T):
    ps = sys.stdin.readline().strip()
    n = int(sys.stdin.readline().strip())
    nums = sys.stdin.readline().strip()
    if n==0:
        nums = deque([])
    else:
        nums = deque(list(map(int, nums[1:-1].split(","))))
    
    is_error = False

    # p 최적화
    p = deque([])
    d_cnt = 0
    r_cnt = 0
    for pc in ps:
        if pc=="D":
            if r_cnt %2 == 1:
                p.append("R")
            r_cnt = 0
            p.append(pc)
            d_cnt +=1
            if d_cnt > n:
                is_error = True
                break
        else:
            r_cnt +=1

    if is_error:
        print("error")
        continue
    
    if r_cnt %2 == 1:
        p.append("R")
        
    if d_cnt == n:
        print("[]")
        continue
    pop_lr = False
    for pcmd in p:
        if pcmd == "R":
            pop_lr = False if pop_lr else True
        else:
            if pop_lr:
                nums.pop()
            else:
                nums.popleft()
    if pop_lr:
        nums.reverse()
    print(f"[{','.join(map(str, nums))}]")