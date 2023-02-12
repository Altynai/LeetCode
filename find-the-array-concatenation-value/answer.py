class Solution:
    def findTheArrayConcVal(self, a: List[int]) -> int:
        i = 0
        j = len(a) - 1

        ans = 0
        while i <= j:
            if i == j:
                ans += a[i]
            else:
                ans += int(str(a[i]) + str(a[j]))
            i += 1
            j -= 1
        return ans
