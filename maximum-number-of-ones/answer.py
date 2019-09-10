class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        cnt = [[0 for j in range(sideLength)] for i in range(sideLength)]
        for i in range(height):
            for j in range(width):
                cnt[i % sideLength][j % sideLength] += 1
        nums = [cnt[i][j] for i in range(sideLength) for j in range(sideLength)]
        nums.sort(reverse=True)
        return sum(nums[:maxOnes])

