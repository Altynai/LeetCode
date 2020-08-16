class Solution:
    def threeConsecutiveOdds(self, a: List[int]) -> bool:
        odd = 0
        for n in a:
            if n & 1:
                odd += 1
            else:
                odd = 0
            if odd >= 3:
                return True
        return False

