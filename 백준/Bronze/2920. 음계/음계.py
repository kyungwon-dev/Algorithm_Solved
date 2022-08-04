import sys
nums = [int(x) for x in input().split()]

ascending = True
if nums[0] > nums[1]:
    ascending = False
for i in range(2,len(nums)):
    if (nums[i-1] > nums[i] and ascending) or (nums[i-1] < nums[i] and not ascending):
        print("mixed")
        sys.exit()
if ascending:
    print("ascending")
else:
    print("descending")