import sys

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        max_profit = 0
        
        # brute force -> Time Limit (10^10 > 10^8)
#         for i in range(len(prices)-1):
#             max_profit = max(max_profit, max(prices[i+1:]) - prices[i])
            
        # 최대 서브 배열 
        min_price = sys.maxsize
        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)
    
        return max_profit

        