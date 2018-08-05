class Solution(object):
    def init(self, edges):
        self.orig = collections.defaultdict(list)
        self.nodes = collections.defaultdict(int)
        for (u, v, w) in edges:
            self.orig[u].append(v)
            self.orig[v].append(u)
            self.nodes[(u, v)] = w
            self.nodes[(v, u)] = w

    def bfs(self, M, N):
        q = collections.deque()
        dis = collections.defaultdict(int)
        cover = collections.defaultdict(int)
        q.append((0, M))
        dis[0] = M

        while q:
            i, m = q.popleft()
            if m == 0:
                continue
            for j in self.orig[i]:
                nodes = self.nodes.get((i, j), 0)
                if m < nodes + 1:
                    cover[(i, j)] = max(cover[(i, j)], m)
                    continue

                if nodes == 0:
                    n = m - 1
                else:
                    cover[(i, j)] = max(cover[(i, j)], nodes)
                    n = m - nodes - 1
                if j not in dis or n > dis[j]:
                    dis[j] = n
                    q.append((j, n))

        ans = len(dis)
        for i in xrange(N):
            for j in self.orig[i]:
                if j < i:
                    continue
                nodes = self.nodes.get((i, j), 0)
                c1 = cover.get((i, j), 0)
                c2 = cover.get((j, i), 0)
                ans += min(c1 + c2, nodes)
        return ans

    def reachableNodes(self, edges, M, N):
        """
        :type edges: List[List[int]]
        :type M: int
        :type N: int
        :rtype: int
        """
        self.init(edges)
        return self.bfs(M, N)
