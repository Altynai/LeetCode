class TopologicalGroup:
    
    def __init__(self, nodes, rules):
        self.nodes = nodes
        degree = collections.defaultdict(int)
        graph = collections.defaultdict(list)
        for (a, b) in rules:
            graph[a].append(b)
            degree[b] += 1
        self.graph = graph
        self.degree = degree
        self.ans = []
        self.visited = {node: False for node in nodes}

    def dfs(self, i):
        self.visited[i] = True
        if i not in self.seen:
            self.ans.append(i)
            self.seen.add(i)
        for j in self.graph[i]:
            if not self.visited[j]:
                self.dfs(j)
        self.visited[i] = False

    def run(self):
        candidates = [i for i in self.nodes if self.degree.get(i, 0) == 0]
        self.ans = candidates
        dq = collections.deque(candidates)
        while dq:
            for j in self.graph[dq.popleft()]:
                self.degree[j] -= 1
                if self.degree[j] == 0:
                    dq.append(j)
                    self.ans.append(j)

        return self.ans if len(self.ans) == len(self.nodes) else []


class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        for i, val in enumerate(group):
            if val == -1:
                group[i] = m
                m += 1
        
        g = collections.defaultdict(list)
        r = collections.defaultdict(list)
        r2 = []
        for i in range(n):
            g[group[i]].append(i)
            for j in beforeItems[i]:
                if group[i] == group[j]:
                    r[group[i]].append((j, i))
                else:
                    r2.append((group[j], group[i]))

        for id, rules in r.items():
            vals = TopologicalGroup(g[id], rules).run()
            if not vals:
                return []
            g[id] = vals

        vals = TopologicalGroup(g.keys(), r2).run()
        if not vals:
            return []
        
        ret = []
        for i in vals:
            ret.extend(g[i])
        return ret

