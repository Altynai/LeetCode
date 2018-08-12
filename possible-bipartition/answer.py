class Solution(object):
    def __build_graph(self, dislikes):
        graph = collections.defaultdict(list)
        for (a, b) in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        return graph

    def __draw(self, graph, u, color):
        color[u] = 1
        dq = collections.deque([u])
        while dq:
            u = dq.popleft()
            for v in graph[u]:
                if v not in color:
                    color[v] = -color[u]
                    dq.append(v)

    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        graph = self.__build_graph(dislikes)
        color = {}
        for u in graph.iterkeys():
            if u not in color:
                self.__draw(graph, u, color)
        for (u, vs) in graph.iteritems():
            for v in vs:
                if color[u] == color[v]:
                    return False
        return True

