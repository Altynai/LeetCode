from collections import defaultdict

class Solution:
    def mostVisited(self, n: int, a: List[int]) -> List[int]:
        c = defaultdict(int)
        now = a[0]
        c[now] += 1
        for i in range(1, len(a)):
            while True:
                now = 1 if now == n else now + 1
                c[now] += 1
                if now == a[i]:
                    break
            
        mx = max(c.values())
        return sorted(k for k, v in c.items() if v == mx)

