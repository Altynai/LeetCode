class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int live = 0, dead = 0;
                for (int k = 0; k < 8; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m)
                        continue;
                    board[ni][nj] & 1 ? live++ : dead;
                }
                if (board[i][j] & 1) {
                    if (live == 2 || live == 3)
                        board[i][j] |= 2;
                } else {
                    if (live == 3)
                        board[i][j] |= 2;
                }
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                board[i][j] >>= 1;
    }
};