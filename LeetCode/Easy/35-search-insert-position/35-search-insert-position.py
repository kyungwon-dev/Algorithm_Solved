class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        idx = bisect.bisect_left(nums, target)
        return idx
        
        # lp, rp = 0, len(nums)-1
        # while lp < rp:
        #     mid = (lp + rp) // 2
        #     if nums[mid] == target:
        #         return mid
        #     elif nums[mid] < target:
        #         lp = mid+1
        #     else:
        #         rp = mid-1
        # return (lp+rp) // 2 + 1