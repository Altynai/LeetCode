class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ans = 0
        for i in range(1, n - 1):
            a = sum(1 for j in range(i) if rating[j] < rating[i])
            b = sum(1 for j in range(i + 1, n) if rating[j] > rating[i])
            c = sum(1 for j in range(i) if rating[j] > rating[i])
            d = sum(1 for j in range(i + 1, n) if rating[j] < rating[i])
            ans += a * b + c * d
        return ans

