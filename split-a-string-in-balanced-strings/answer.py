class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt, ans = 0, 0
        for ch in s:
            cnt += 1 if ch == 'L' else -1
            ans += 1 if cnt == 0 else 0
        return ans

