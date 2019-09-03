class Solution:
    def point(self, calory, low, upper):
        if calory < low:
            return -1
        return 1 if calory > upper else 0

    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        total = sum(calories[:k])
        ans = self.point(total, lower, upper)
        for i in range(k, len(calories)):
            total = total + calories[i] - calories[i - k]
            ans += self.point(total, lower, upper)
        return ans

