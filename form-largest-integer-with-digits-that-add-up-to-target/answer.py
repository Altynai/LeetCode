def array(a, val=None):
    return [val for _ in range(a)]

class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        digits = {cost[i]: i + 1 for i in range(9)}
        # number, value
        digits = [(v, k) for k, v in digits.items()]
        digits.sort(reverse=True)
        n = len(digits)

        dp = array(target + 1, None)
        dp[0] = 0
        for i in range(1, target + 1):
            for (num, val) in digits:
                if i < val or dp[i - val] is None:
                    continue
                if dp[i] is None or dp[i - val] + 1 > dp[i]: 
                    dp[i] = dp[i - val] + 1

        if dp[target] is None:
            return "0"

        ans = []
        while target > 0:
            for (num, val) in digits:
                if target >= val and dp[target - val] == dp[target] - 1:
                    ans.append(num)
                    target -= val
                    break
        ans.sort(reverse=True)
        return "".join(map(str, ans))

