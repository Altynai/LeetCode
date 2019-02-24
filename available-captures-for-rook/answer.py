class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        def getRook():
            for i in range(0, 8):
                for j in range(0, 8):
                    if board[i][j] == 'R':
                        return (i, j)
            return None
    
        rx, ry = getRook()
        ans = 0
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        
        for k in range(4):
            x = rx + dx[k]
            y = ry + dy[k]
            while 0 <= x < 8 and 0 <= y < 8:
                if board[x][y].isupper():
                    break
                elif board[x][y].islower():
                    ans += 1
                    break
                x = x + dx[k]
                y = y + dy[k]

        return ans

