# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        if n==1:
            return n
        lp, rp = 0, n
        while lp < rp:
            mid = (lp + rp) //2 + 1
            if isBadVersion(mid):
                rp = mid-1
            else:
                lp = mid+1
        mid = (lp + rp) // 2
        if isBadVersion(mid):
            while isBadVersion(mid):
                mid -=1
                return mid+1
        else:
            while not isBadVersion(mid):
                mid +=1
                return mid

        
    
        
        
    