class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda t: t[1] - t[0], reverse=True)
        ans = got = 0
        for (c, m) in tasks:
            if m > got:
                ans += m - got
                got = m
            got -= c
        return ans
