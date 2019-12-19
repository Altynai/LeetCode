class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        stack = []
        for interval in intervals:
            if not stack:
                stack.append(interval)
            else:
                top = stack[-1]
                if interval[1] > top[1]:
                    stack.append(interval)
        return len(stack)

