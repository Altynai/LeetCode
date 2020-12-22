class Solution:
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        vals = [(a[i] + b[i], i) for i in range(n)]
        vals.sort(reverse=True)
        
        sa = sb = 0
        alice = 1
        for val, i in vals:
            if alice:
                sa += a[i]
            else:
                sb += b[i]
            alice ^= 1

        if sa == sb:
            return 0
        return 1 if sa > sb else -1

