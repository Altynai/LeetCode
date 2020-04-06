class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        pos = sorted(s for s in satisfaction if s >= 0)
        neg = sorted((s for s in satisfaction if s < 0), reverse=True)
        n, m = len(pos), len(neg)
        if n == 0:
            return 0

        tp = sum(pos)
        sp = [0 for _ in range(m + 2)]
        sp[1] = sum((i + 1) * pos[i] for i in range(n))
        for i in range(2, m + 2):
            sp[i] = sp[i - 1] + tp

        if m == 0:
            return sp[1]

        np = [0 for _ in range(m + 1)]
        np[1] = neg[0]
        tn = neg[0]
        for i in range(2, m + 1):
            tn += neg[i - 1]
            np[i] = np[i - 1] + tn

        return max(sp[i] + np[i - 1] for i in range(1, m + 2))

