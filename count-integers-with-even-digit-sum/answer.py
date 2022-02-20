class Solution:
    def countEven(self, num: int) -> int:
        ans = 0
        for x in range(2, num + 1):
            if (sum(map(int, str(x))) % 2 == 0):
                ans += 1
        return ans
