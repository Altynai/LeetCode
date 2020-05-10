class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        g = collections.defaultdict(list)
        for (u, v) in edges:
            g[u].append(v)
            g[v].append(u)
        
        vis = set()
        def dfs(r):
            vis.add(r)
            has = hasApple[r]
            ans = 0
            for son in g[r]:
                if son in vis:
                    continue
                has2, walks = dfs(son)
                if has2:
                    ans += walks + 2
                    has |= has2

            return (has, ans)

        return dfs(0)[1]

