class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        
        ans = []
        n = len(prices)
        for i in range(n):
            ans.append(prices[i])
            for j in range(i + 1, n):
                if prices[j] <= prices[i]:
                    ans[i] -= prices[j]
                    break
        return ans

