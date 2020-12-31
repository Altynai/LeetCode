from heapq import *

class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        pq = []
        n = len(apples)
        ans = 0

        def clean(when):
            while pq and pq[0][0] < when:
                heappop(pq)
        
        def eat():
            assert(len(pq))
            (when, apple) = heappop(pq)
            apple -= 1
            if apple > 0:
                heappush(pq, (when, apple))

        for i in range(n):
            clean(i)
            if apples[i]:
                heappush(pq, (i + days[i] - 1, apples[i]))
            if pq:
                eat()
                ans += 1
        
        day = n
        while pq:
            clean(day)
            if not pq:
                break
            eat()
            ans += 1
            day += 1
        
        return ans

