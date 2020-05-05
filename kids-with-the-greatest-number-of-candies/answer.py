class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        mx = max(candies)
        return [extraCandies + c >= mx for _, c in enumerate(candies)]

