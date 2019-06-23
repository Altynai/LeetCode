class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        jobs = []
        for trip in trips:
            jobs.append((trip[1], trip[0]))
            jobs.append((trip[2], -trip[0]))
        jobs.sort()
        current = 0
        for job in jobs:
            current += job[1]
            if current > capacity:
                return False
        return True

