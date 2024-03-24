def solution(x, y, n):
    answer = 0
    nums = [10000000 for _ in range(1000001)]
    
    nums[x] = 0
    
    for i in range(x+1, y+1):
        
        if i%2 == 0:
            nums[i] = min(nums[i], nums[ int(i/2)] + 1)
        
        if i%3 == 0:
            nums[i] = min(nums[i], nums[ int(i/3)] + 1)
        
        if i-n > 0:
            nums[i] = min(nums[i], nums[ i- n] + 1)

    if nums[y] == 10000000:
        nums[y] = -1
    return nums[y]