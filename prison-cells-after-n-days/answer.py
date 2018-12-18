class Solution:
    
    def join(self, cells):
        return ' '.join(map(str, cells))

    def move(self, cells):
        ans = [0 for _ in range(8)]
        for i in range(1, 7):
            ans[i] = int(cells[i - 1] == cells[i + 1])
        return ans

    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        cell = self.join(cells)
        seen = {cell}
        ans = [cell]

        while True:
            cells = self.move(cells)
            cell = self.join(cells)
            if cell in seen:
                break
            seen.add(cell)
            ans.append(cell)

        
        p = ans.index(cell)
        assert p != -1
        if N <= p:
            return list(map(int, ans[N].split()))

        N -= p - 1
        ans = ans[p:]
        m = len(ans)
        if N % m == 0:
            N = m
        else:
            N %= m
        return list(map(int, ans[N - 1].split()))

