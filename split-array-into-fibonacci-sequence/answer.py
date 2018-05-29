class Solution(object):

    def leadZero(self, S, i, j):
        return i + 1 < j and S[i] == "0"

    def toStr(self, nums):
        return "".join(map(str, nums))

    def equals(self, S, nums):
        return S == self.toStr(nums)

    def splitIntoFibonacci(self, S):
        n = len(S)
        threshold = (2 ** 31) - 1
        for i in xrange(1, n - 2):
            a = int(S[:i])
            if a > threshold:
                break
            for j in xrange(i + 1, n - 1):
                b = int(S[i:j])
                if b > threshold:
                    break
                if self.leadZero(S, 0, i) or self.leadZero(S, i, j):
                    continue
                nums = [a, b]
                while len(self.toStr(nums)) < n:
                    c = nums[-2] + nums[-1]
                    if c > threshold:
                        break
                    nums.append(c)

                if self.equals(S, nums):
                    return nums
        return []
