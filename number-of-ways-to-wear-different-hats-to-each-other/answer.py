from collections import defaultdict

class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        n = len(hats)
        mod = 1000000000 + 7
        likes = defaultdict(list)
        for i, hs in enumerate(hats):
            for h in hs:
                likes[h].append(i)
        
        ids = list(likes.keys())
        dp = {0: 1}

        for i in ids:
            dp2 = defaultdict(int)
            for state, num in dp.items():
                for k in likes[i]:
                    # person
                    if state & (1 << k):
                        continue
                    dp2[state | (1 << k)] = (dp2[state | (1 << k)] + num) % mod

            for state, num in dp.items():
                dp2[state] = (dp2[state] + num) % mod
        
            dp = dp2
    
        ans = 0
        for state, num in dp.items():
            if state == (1 << n) - 1:
                ans = (ans + num) % mod
        return ans
                
