class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        n, m = len(mat), len(mat[0])
        hp = [-mat[0][j] for j in range(min(m, k))]
        heapq.heapify(hp)
        
        for i in range(1, n):
            hp2 = []
            while hp:
                val = -heapq.heappop(hp)
                for j in range(m):
                    newVal = val + mat[i][j]
                    if len(hp2) < k:
                        heapq.heappush(hp2, -newVal)
                    elif len(hp2) == k and newVal < -hp2[0]:
                        heapq.heappop(hp2)
                        heapq.heappush(hp2, -newVal)
            hp = hp2

        return -hp[0]

