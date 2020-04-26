from collections import deque

class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        dq = deque([(0, 0)])
        ans = []
        contains = {(0, 0)}

        while dq:
            (x, y) = dq.popleft()
            ans.append(nums[x][y])
            contains.remove((x, y))
            
            if x + 1 < n and y < len(nums[x + 1]) and (x + 1, y) not in contains:
                dq.append((x + 1, y))
                contains.add((x + 1, y))
            
            if y + 1 < len(nums[x]) and (x, y + 1) not in contains:
                dq.append((x, y + 1))
                contains.add((x, y + 1))

        return ans

