class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        if max(horizontalCuts) != h:
            horizontalCuts.append(h)
        if min(horizontalCuts) != 0:
            horizontalCuts.append(0)
        horizontalCuts.sort()
        
        if max(verticalCuts) != w:
            verticalCuts.append(w)
        if min(verticalCuts) != 0:
            verticalCuts.append(0)
        verticalCuts.sort()

        return max(horizontalCuts[i] - horizontalCuts[i - 1] for i in range(1, len(horizontalCuts))) *\
            max(verticalCuts[i] - verticalCuts[i - 1] for i in range(1, len(verticalCuts))) %\
            1000000007

