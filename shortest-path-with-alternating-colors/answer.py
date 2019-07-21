class Solution:

    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        RED = 0
        BLUE = 1

        edges = [collections.defaultdict(list) for _ in range(2)]
        for (a, b) in red_edges:
            edges[RED][a].append(b)
        for (a, b) in blue_edges:
            edges[BLUE][a].append(b)

        mins = [[-1, -1] for _ in range(n)]
        mins[0] = [0, 0]
        q = collections.deque()
        q.append(0)

        while q:
            i = q.pop()
            for color in (RED, BLUE):
                if mins[i][color] == -1:
                    continue
                for j in edges[color ^ 1][i]:
                    if mins[j][color ^ 1] == -1 or mins[i][color] + 1 < mins[j][color ^ 1]:
                        mins[j][color ^ 1] = mins[i][color] + 1
                        q.append(j)

        return [min((item for item in items if item != -1), default=-1) for items in mins]

