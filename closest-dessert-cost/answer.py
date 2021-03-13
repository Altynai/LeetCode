class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        ans = [math.inf]
        best = [math.inf]
        m = len(toppingCosts)

        def update(now):
            cost = abs(target - now)
            if cost < ans[0] or (cost == ans[0] and now < best[0]):
                ans[0] = cost
                best[0] = now

        for base in baseCosts:
            update(base)
            
            for i in range(1, 1 << m):
                s = []
                for j in range(m):
                    if i & (1 << j):
                        s.append(j)
                
                n = len(s)
                for j in range(1 << n):
                    now = base
                    for k in range(n):
                        if j & (1 << k):
                            now += toppingCosts[s[k]] * 2
                        else:
                            now += toppingCosts[s[k]]
                    update(now)

        return best[0]

