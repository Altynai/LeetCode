class Solution:
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        hp = []
        for point in points:
            d = point[0] ** 2 + point[1] ** 2
            item = (-d, point[0], point[1])
            heapq.heappush(hp, item)
            if len(hp) > K:
                heapq.heappop(hp)
        return [[item[1], item[2]] for item in hp]

