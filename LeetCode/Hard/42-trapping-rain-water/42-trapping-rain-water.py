class Solution:
    def trap(self, height: List[int]) -> int:
        
        volume = 0
        lp , rp = 0, len(height)-1
        left_max, right_max = height[lp], height[rp]
        while lp <= rp:
            left_max = max(height[lp], left_max)
            right_max = max(height[rp], right_max)
            
            if left_max <= right_max:
                volume += left_max - height[lp]
                lp +=1
            else:
                volume += right_max - height[rp]
                rp -=1
        return volume