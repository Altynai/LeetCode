class Solution:
    def circularPermutation(self, n: int, start: int) -> List[int]:
        ans = [0, 1]
        for i in range(1, n):
            ans.extend([j + (1<< i) for j in ans[::-1]])
        index = ans.index(start)
        return ans[index:] + ans[:index]

