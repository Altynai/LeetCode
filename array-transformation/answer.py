class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        n = len(arr)
        a = arr[:]
        same = False
        while not same:
            b = a[:]
            for i in range(1, n - 1):
                if a[i - 1] < a[i] > a[i + 1]:
                    b[i] -= 1
                if a[i - 1] > a[i] < a[i + 1]:
                    b[i] += 1
            same = (a == b)
            a = b[:]
        return a

