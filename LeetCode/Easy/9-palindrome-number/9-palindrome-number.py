class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        if "".join(reversed(x)) == x:
            return True
        return False