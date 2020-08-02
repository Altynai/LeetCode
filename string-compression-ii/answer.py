class Solution:
    def getLengthOfOptimalCompression(self, s: str, K: int) -> int:
        
        n = len(s)

        def length(cnt):
            return cnt if cnt <= 1 else 1 + len(str(cnt))

        @lru_cache(None)
        def dfs(i, k, last, cnt):
            if i == n:
                return length(cnt)
            
            # delete
            ans = inf
            if k > 0:
                ans = min(ans, dfs(i + 1, k - 1, last, cnt))
            
            # keep
            j = ord(s[i]) - ord('a')
            if j == last:
                return min(ans, dfs(i + 1, k, last, cnt + 1))
            else:
                return min(ans, length(cnt) + dfs(i + 1, k, j, 1))

        return dfs(0, K, 26, 0)

