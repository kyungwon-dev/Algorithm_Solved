class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = set()
        nums.sort()
        
        for idx in range(len(nums)-2) :
            left = idx+1
            right = len(nums)-1
            while left < right:
                subsum = nums[idx] + nums[left] + nums[right]
                if subsum <= 0:
                    if subsum == 0:
                        rs = tuple(sorted([nums[idx],nums[left],nums[right]]))
                        answer.add(rs)
                    left += 1
                else:
                    right -=1

        return [list(x) for x in answer]
            