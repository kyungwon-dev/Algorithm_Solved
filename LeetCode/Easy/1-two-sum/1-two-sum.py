class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for idx, val in enumerate(nums):
            complement = target - val
            print(complement)
            if complement in nums[idx+1:]:
                return [idx, nums[idx+1:].index(complement) + idx + 1]

        
        
        # for i in range(len(nums)):    
        #     for j in range(i+1,len(nums)):
        #         if nums[i]+nums[j] == target:
        #             return [i,j]