class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)

        def count(row):
            cnt = 0
            for i in range(n - 1, -1, -1):
                if row[i] == 1:
                    break
                cnt += 1
            return cnt
    
        rows = [(count(r), r) for r in grid]
        ans = 0

        i = 0
        need = n - 1
        while i <= n - 2:
            j = i
            while j < n and rows[j][0] < need:
                j += 1
            if j == n:
                return -1
            
            for k in range(j, i, -1):
                rows[k], rows[k - 1] = rows[k - 1], rows[k]
                ans += 1
            
            need -= 1
            i += 1
            
        return ans
