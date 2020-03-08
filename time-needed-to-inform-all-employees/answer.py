from collections import defaultdict

class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        g = defaultdict(list)
        for i, m in enumerate(manager):
            if m == -1:
                root = i
            else:
                g[m].append(i)

        def dfs(r):
            return 0 if r not in g else informTime[r] + max(dfs(v) for v in g[r])
        
        return dfs(root)

