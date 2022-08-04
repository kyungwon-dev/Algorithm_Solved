class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_map = {}
        # key : value => idx: val
        for idx, val in enumerate(nums):
            nums_map[val] = idx
        # find target - val
        for idx, val in enumerate(nums):
            if target - val in nums_map and idx != nums_map[target - val]:
                return [idx, nums_map[target - val]]
        
        # for idx, val in enumerate(nums):
        #     complement = target - val
        #     print(complement)
        #     if complement in nums[idx+1:]:
        #         return [idx, nums[idx+1:].index(complement) + idx + 1]

        # for i in range(len(nums)):    
        #     for j in range(i+1,len(nums)):
        #         if nums[i]+nums[j] == target:
        #             return [i,j]