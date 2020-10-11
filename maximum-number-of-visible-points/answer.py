class Solution:
    def visiblePoints(self, p: List[List[int]], angle: int, location: List[int]) -> int:
        x, y = location
        
        deg = []
        same = 0
        for (x1, y1) in p:
            if x1 == x and y1 == y:
                same += 1
                continue
            dr = math.atan2(y1 - y, x1 - x)
            dg = math.degrees(dr)
            deg.append((dg + 360) % 360)
        
        deg.sort()
        n = len(deg)
        cnt = [0 for _ in range(n)]
        uniq = 0
        ans = 0
        
        def check(da, db):
            if da >= db:
                return da - db > angle
            return da + 360 - db > angle

        q = collections.deque()
        for i in range(n + n):
            q.append(i % n)
            cnt[i % n] += 1
            if cnt[i % n] == 1:
                uniq += 1
            
            while q and check(deg[i % n], deg[q[0]]):
                cnt[q[0]] -= 1
                if cnt[q[0]] == 0:
                    uniq -= 1
                q.popleft()
            ans = max(ans, uniq)

        return ans + same
