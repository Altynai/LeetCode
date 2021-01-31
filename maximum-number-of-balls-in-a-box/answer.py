class Solution:
    def countBalls(self, l: int, r: int) -> int:
        cnt = collections.defaultdict(int)
        for i in range(l, r + 1):
            s = sum(map(int, str(i)))
            cnt[s] += 1
        return max(cnt.values())
