str = input()
nums = str.split("-")
sign = 1;
if nums[0] == '':
    sign = -1
    nums = nums[1:]
rs = []
for num in nums:
    if "+" in num:
        num_sum = sum(list(map(int, num.split("+"))))
        rs.append(num_sum)
    else:
        rs.append(int(num))
answer = rs[0] * sign
for i in range(1,len(nums)):
    answer -= rs[i]
    
print(answer)