"""
Tips:
1. this code fails on the last test case, but algorithm works just fine.
2. you can make some list comprehensions at the begin, which means to use golbal
    variables, this code spents too much time on memery allocation.
"""

import collections


class Edge(object):

    def __init__(self):
        self.v = 0
        self.w = 0
        self.next = -1


class Graph(object):

    def __init__(self, n):
        self.edges = []
        self.head = [-1 for _ in xrange(n)]
        self.n = n

    def insert(self, u, v, w):
        edge = Edge(v, w)
        edge.next = self.head[u]
        self.edges.append(edge)
        self.head[u] = len(self.edges) - 1

    def spfa(self, s, t):
        inQueue = [False for _ in xrange(self.n)]
        distance = [-1 for _ in xrange(self.n)]
        queue = collections.deque()
        queue.appendleft(s)
        inQueue[s] = True
        distance[s] = 0

        while len(queue):
            u = queue.pop()
            inQueue[u] = False
            p = self.head[u]
            while p != -1:
                v = self.edges[p].v
                w = self.edges[p].w
                if distance[v] == -1 or distance[u] + w < distance[v]:
                    distance[v] = distance[u] + w
                    if not inQueue[v]:
                        queue.appendleft(v)
                        inQueue[v] = True
                p = self.edges[p].next

        if distance[t] == -1:
            return -1
        return distance[t] + 1


class Solution(object):

    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if S == T:
            return 0

        trans = collections.defaultdict(list)
        for index, route in enumerate(routes, 1):
            for num in route:
                trans[num].append(index)

        # source: 0
        # ids: 1 ~ n
        # sink: n + 1
        n = len(routes)
        source = 0
        sink = n + 1
        graph = Graph(n + 2)

        for indexes in trans.itervalues():
            for i in xrange(len(indexes)):
                u = indexes[i]
                for j in xrange(i + 1, len(indexes)):
                    v = indexes[j]
                    graph.insert(u, v, 1)
                    graph.insert(v, u, 1)

        for i in trans[S]:
            graph.insert(source, i, 0)
        for i in trans[T]:
            graph.insert(i, sink, 0)

        return graph.spfa(source, sink)
