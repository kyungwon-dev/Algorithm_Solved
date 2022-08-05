nums = []
for i in range(5):
    nums.append(int(input()))
print(f"{min(nums[:3]) + min(nums[3],nums[4]) - 50}")