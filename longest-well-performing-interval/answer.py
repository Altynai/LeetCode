class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        n = len(hours)
        s = [0 for _ in range(n + 1)]
        for i in range(1, n + 1):
            s[i] = s[i - 1] + int(hours[i - 1] > 8)
        items = [
            (2 * s[i] - i, i)
            for i in range(n + 1)
        ]
        items.sort()
        
        ans = max((items[i][1] for i in range(1, n + 1) if items[i][0] > 0), default=0)
        i, j = 0, 0
        index = -1
        while i <= n:
            while j <= n and items[i][0] == items[j][0]:
                j += 1
            if index == -1:
                index = min(items[k][1] for k in range(i, j))
            else:
                for k in range(i, j):
                    ans = max(ans, items[k][1] - index)
            for k in range(i, j):
                index = min(index, items[k][1])
            i = j

        return ans
        
