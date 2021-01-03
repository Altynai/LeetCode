class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda b: b[1], reverse=True)
        ans = 0
        for (num, unit) in boxTypes:
            cnt = min(num, truckSize)
            ans += cnt * unit
            truckSize -= cnt
        return ans

