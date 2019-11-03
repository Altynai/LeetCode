import collections

class Solution:
    
    def dfs(self, u, len):
        self.vis[u] = True
        if len > self.max_len:
            self.max_len = len
            self.max_node = u

        for v in self.graph[u]:
            if not self.vis[v]:
                self.dfs(v, len + 1)
        
    def treeDiameter(self, edges: List[List[int]]) -> int:
        graph = collections.defaultdict(list)
        for (a, b) in edges:
            graph[a].append(b)
            graph[b].append(a)
        self.graph = graph
        self.n = len(edges) + 1

        self.vis = [False for _ in range(self.n)]
        self.max_len = 0
        self.max_node = 0
        self.dfs(0, 0)
        
        root = self.max_node
        self.vis = [False for _ in range(self.n)]
        self.max_len = 0
        self.max_node = 0
        self.dfs(root, 0)
        return self.max_len

