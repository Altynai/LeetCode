from heapq import heappush, heappop

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        items = sorted(zip(efficiency, speed), reverse=True)
        h, sum, ans, me = [], 0, 0, items[0][0]
        for (e, s) in items:
            me = min(e, me)
            if len(h) < k:
                heappush(h, s)
                sum += s
            elif s > h[0]:
                sum -= h[0]
                heappop(h)
                sum += s
                heappush(h, s)
            ans = max(ans, sum * me)
        return ans % (1000000000 + 7)

