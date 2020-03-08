from collections import defaultdict

class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        g = defaultdict(list)
        for (u, v) in edges:
            g[u].append(v)
            g[v].append(u)

        vis = set()
        ans = [0.0]

        def dfs(r, seconds, p):
            vis.add(r)
            nodes = list(v for v in g[r] if v not in vis)
            if r == target:
                if t == seconds or (t > seconds and not nodes):
                    ans[0] = p
                return

            if not nodes:
                return
            
            q = 1.0 / len(nodes)
            for v in nodes:
                dfs(v, seconds + 1, p * q)
    
        dfs(1, 0, 1.0)
        return ans[0]

