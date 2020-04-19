class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        m = 3 * (2 ** (n - 1))
        if k > m:
            return ""
    
        chs = ['' for _ in range(n)]
        ans = []

        def dfs(i, pre):
            if i == n:
                ans.append(''.join(chs))
                return
            
            for ch in ["a", "b", "c"]:
                if ch != pre:
                    chs[i] = ch
                    dfs(i + 1, ch)
        
        dfs(0, "")
        ans.sort()
        return ans[k - 1]

