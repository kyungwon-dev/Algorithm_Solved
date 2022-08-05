class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        multiple_except_self_nums = []
        # left multiple
        p = 1
        for i in range(len(nums)):
            multiple_except_self_nums.append(p)
            p *= nums[i]

        #right multiple
        p=1
        for i in range(len(nums)-1, -1, -1):
            multiple_except_self_nums[i] *= p
            p *= nums[i]
        
        return multiple_except_self_nums
            