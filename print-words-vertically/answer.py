class Solution:
    def printVertically(self, s: str) -> List[str]:
        words = s.split(' ')
        n, m = max(len(w) for w in words), len(words)
        mat = [[' ' for j in range(m)] for i in range(n)]
        for j, w in enumerate(words):
            for i, ch in enumerate(w):
                mat[i][j] = ch
        return [''.join(mat[i]).rstrip(' ') for i in range(n)]

