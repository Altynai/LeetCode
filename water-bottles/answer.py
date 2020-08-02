class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        empty = numBottles
        while empty >= numExchange:
            full = empty // numExchange
            empty %= numExchange
            ans += full
            empty += full
        return ans

