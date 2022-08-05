class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # lp , rp = 0, len(nums)-1
        # while lp <= rp:
        #     mid = (lp + rp) // 2
        #     if nums[mid] == target:
        #         return mid
        #     elif nums[mid] < target:
        #         lp = mid+1
        #     else:
        #         rp = mid-1
        # return -1
            
        # using bitsect
        t = bisect.bisect_left(nums, target)
        return t if t < len(nums) and nums[t] == target else -1