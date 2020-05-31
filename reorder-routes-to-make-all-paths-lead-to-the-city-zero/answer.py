from collections import defaultdict

class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        g = defaultdict(list)
        for (u, v) in connections:
            g[u].append(v)
            g[v].append(u)
        
        level = {}
        def dfs(cur, l):
            level[cur] = l
            for nxt in g[cur]:
                if nxt not in level:
                    dfs(nxt, l + 1)
        
        dfs(0, 0)
        return sum(1 for (u, v) in connections if level[u] + 1 == level[v])

