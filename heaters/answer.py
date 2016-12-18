
from bisect import bisect_left


class Solution(object):

    def setup(self, houses, heaters):
        houses.sort()
        heaters.sort()
        self.houses = houses
        self.heaters = heaters

    def solution(self):
        best = 0
        for house in self.houses:
            index = min(bisect_left(self.heaters, house), len(self.heaters) - 1)
            distance1 = abs(self.heaters[index] - house)
            distance2 = abs(self.heaters[max(index - 1, 0)] - house)
            distance = min(distance1, distance2)
            best = max(distance, best)
        return best

    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        self.setup(houses, heaters)
        return self.solution()
