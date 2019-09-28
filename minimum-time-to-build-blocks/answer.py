import heapq

class Solution:
    def minBuildTime(self, blocks, split):
        heapq.heapify(blocks)
        while len(blocks) >= 2:
            x, y = heapq.heappop(blocks), heapq.heappop(blocks)
            heapq.heappush(blocks, y + split)
        return blocks[0]


