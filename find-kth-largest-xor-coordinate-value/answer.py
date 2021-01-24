from heapq import *

class Solution:
    def kthLargestValue(self, mat: List[List[int]], k: int) -> int:
        n, m = len(mat), len(mat[0])
        hp = []
        for i in range(n):
            for j in range(m):
                if j:
                    mat[i][j] ^= mat[i][j - 1]
                if i:
                    mat[i][j] ^= mat[i - 1][j]
                if i and j:
                    mat[i][j] ^= mat[i - 1][j - 1]
                
                heappush(hp, mat[i][j])
                if len(hp) > k:
                    heappop(hp)
        
        return hp[0]

