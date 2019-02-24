class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        cnt = collections.defaultdict(int)
        pairs = set()
        for (a, b) in trust:
            cnt[a] += 1
            pairs.add((a, b))
        
        def everyoneTrust(x):
            for i in range(1, N + 1):
                if i != x and (i, x) not in pairs:
                    return False
            return True

        ans = []
        for i in range(1, N + 1):
            if cnt[i] == 0 and everyoneTrust(i):
                ans.append(i)

        return ans[0] if len(ans) == 1 else -1

