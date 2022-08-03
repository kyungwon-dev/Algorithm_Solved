class Solution:
    
    def longestPalindrome(self, s: str) -> str:
        # 입력된 s 자체가 팰린드롬
        if len(s) == 1 or s == s[::-1]:
            return s
            
        def find_palindrom(left:int, right:int) -> str:
            while left >=0 and right<len(s) and s[left] == s[right]:
                left -=1
                right +=1                
            return s[left+1:right]
        
        answer = ""
        for idx in range(len(s)-1):
            answer = max(answer,
                         find_palindrom(idx, idx+1),
                         find_palindrom(idx, idx+2),
                         key=len)
        return answer