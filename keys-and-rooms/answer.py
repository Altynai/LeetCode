class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        n = len(rooms)
        vis = [False for _ in xrange(n)]

        def dfs(cur):
            vis[cur] = True
            for room in rooms[cur]:
                if not vis[room]:
                    dfs(room)

        dfs(0)
        return all(vis)

