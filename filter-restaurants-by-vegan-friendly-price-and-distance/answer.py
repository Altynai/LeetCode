class Solution:
    def filterRestaurants(self, restaurants: List[List[int]], veganFriendly: int, maxPrice: int, maxDistance: int) -> List[int]:
        def f(r):
            return not (r[2] == 0 and veganFriendly == 1) and r[3] <= maxPrice and r[4] <= maxDistance
        return [r[0] for r in sorted((r for r in restaurants if f(r)), key=lambda x: (-x[1], -x[0]))]

