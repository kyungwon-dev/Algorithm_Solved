N = input()
nums = [x for x in input().split()]
target = input()
print(sum([1 for x in nums if x==target]))