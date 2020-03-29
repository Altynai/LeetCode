from collections import defaultdict

class UndergroundSystem:

    def __init__(self):
        self.times = defaultdict(int)
        self.count = defaultdict(int)
        self.state = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.state[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        (name, when) = self.state[id]
        self.times[(name, stationName)] += t - when
        self.count[(name, stationName)] += 1
        del self.state[id]

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        return self.times[(startStation, endStation)] / self.count[(startStation, endStation)]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
