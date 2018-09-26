class Solution(object):
    def decode(self, where):
        if where % self.n == 0:
            x, y = where / self.n - 1, self.n - 1
        else:
            x, y = where / self.n, where % self.n - 1
        if x % 2 == 1:
            y = self.n - 1 - y
        x = self.n - 1 - x
        return x, y

    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        self.board = board
        self.n = len(board)
        self.nn = self.n * self.n
        self.cache = {i:self.decode(i) for i in xrange(1, self.nn + 1)}

        mx = 99999999
        dis = [[mx for i in xrange(self.n)] for j in xrange(self.n)]
        dis[self.n - 1][0] = 0

        dq = collections.deque()
        dq.append(1)
        while dq:
            where = dq.popleft()
            x, y = self.cache[where]
            best = dis[x][y]
            for move in xrange(1, 7):
                nxt = where + move
                if nxt > self.nn:
                    continue

                nx, ny = self.cache[nxt]
                if self.board[nx][ny] != -1:
                    nxt = self.board[nx][ny]

                x, y = self.cache[nxt]
                if best + 1 < dis[x][y]:
                    dis[x][y] = best + 1
                    dq.append(nxt)

        x, y = self.cache[self.nn]
        return -1 if dis[x][y] == mx else dis[x][y]

