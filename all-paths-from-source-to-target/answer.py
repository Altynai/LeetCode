class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(graph)
        path = [0] * n
        ans = []
        
        def dfs(s, i):
            path[i] = s
            if s == n - 1:
                ans.append(path[:i + 1])
            else:
                for e in graph[s]:
                    dfs(e, i + 1)
        
        dfs(0, 0)
        return ans

