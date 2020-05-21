class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        
        def gcd(a, b):
            if b == 0:
                return a
            return gcd(b, a % b)

        ans = set()
        for i in range(1, n + 1):
            for j in range(1, i):
                c = gcd(i, j)
                s = '{0}/{1}'.format(j // c, i // c)
                ans.add(s)
        return list(ans)
