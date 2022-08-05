class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        answer = []
        nums.sort()
        
        for idx in range(len(nums)-2) :
            left, right = idx+1, len(nums)-1
            
            if idx > 0 and nums[idx] == nums[idx-1]:
                continue
            
            while left < right:
                subsum = nums[idx] + nums[left] + nums[right]
                
                if subsum < 0:
                    left +=1
                elif subsum > 0:
                    right -=1
                else:
                    answer.append([nums[idx], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left+=1
                    while left < right and nums[right] == nums[right - 1]:
                        right-=1
                    left +=1
                    right -=1
        
        return answer
            