class Solution:
    def canEat(self, candies: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(candies)
        s = [0 for _ in range(n)]
        s[0] = candies[0]
        for i in range(1, n):
            s[i] = s[i - 1] + candies[i]
        
        m = len(queries)
        ans = [True for _ in range(m)]
        for i, (_type, day, mx) in enumerate(queries):
            # eat 1 per day
            if day >= s[_type]:
                ans[i] = False
                continue

            # eat max per day
            # after `day` days, still can't eat all [0, _type - 1]
            total = 0 if _type == 0 else s[_type - 1]
            canEat = mx * (day + 1)
            if canEat <= total:
                ans[i] = False
            
        return ans
