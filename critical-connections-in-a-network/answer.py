class Solution:

    def tarjan(self, u, parent):
        self.dfn[u] = self.low[u] = self.id
        self.id += 1

        for v in self.graph[u]:
            if v == parent:
                continue
            elif self.dfn[v] == -1:
                self.tarjan(v, u)
                self.low[u] = min(self.low[u], self.low[v])
                if self.low[v] > self.dfn[u]:
                    self.ans.append([u, v])
            else:
                self.low[u] = min(self.low[u], self.dfn[v])

    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph = collections.defaultdict(list)
        for (u, v) in connections:
            graph[u].append(v)
            graph[v].append(u)
            
        self.graph = graph
        self.id = 0
        self.dfn = [-1 for _ in range(n)]
        self.low = [-1 for _ in range(n)]
        self.ans = []
        self.tarjan(0, 0)

        return self.ans

