class Solution:
    def maxDiff(self, num: int) -> int:
        x = str(num)
        n = len(x)
        a, b = str(num), str(num)
        for i in range(n):
            if a[i] != '9':
                a = a.replace(a[i], '9')
                break
        
        for i in range(n):
            if b[i] not in "01":
                b = b.replace(b[i], '1' if i == 0 else '0')
                break

        return int(a) - int(b)

