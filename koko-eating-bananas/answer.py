class Solution(object):
    def hours(self, piles, speed):
        cnt = 0
        for pile in piles:
            cnt += (pile + speed - 1) / speed
        return cnt

    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """
        piles.sort()
        low, high = 1, piles[-1] if piles else 1
        ans = high
        while low <= high:
            speed = (low + high) / 2
            h = self.hours(piles, speed)
            if h <= H:
                ans = speed
                high = speed - 1
            else:
                low = speed + 1
        return ans

