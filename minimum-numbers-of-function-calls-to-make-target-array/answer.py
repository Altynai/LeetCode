class Solution:
    def minOperations(self, a: List[int]) -> int:
        n = len(a)
        ans = 0
        while any(val > 0 for val in a):
            for i in range(n):
                if a[i] & 1:
                    ans += 1
                    a[i] -= 1
            if max(a) == 0:
                break
            for i in range(n):
                a[i] = a[i] // 2
            ans += 1
        return ans
                
