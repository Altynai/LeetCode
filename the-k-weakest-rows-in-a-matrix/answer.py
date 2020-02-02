class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        return [v[1] for v in sorted((sum(row), i) for i, row in enumerate(mat))[:k]]

