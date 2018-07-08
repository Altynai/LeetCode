int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution {
private:
    int n, m, mask, minm;
    vector<string> grid;
    int dp[32][32][1 << 6];

    void init(vector<string>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        mask = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (islower(grid[i][j]))
                    mask |= 1 << (grid[i][j] - 'a');
            }
        }
    }

    bool outside(int i, int j) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    bool hasKey(int keys, int i) {
        return (keys & (1 << i)) > 0;
    }

    void dfs(int i, int j, int move, int keys) {
        if (minm != -1 && move >= minm)
            return;
        if (islower(grid[i][j]))
            keys |= 1 << (grid[i][j] - 'a');
        if (dp[i][j][keys] != -1 && move >= dp[i][j][keys])
            return;
        dp[i][j][keys] = move;
        if (keys == mask) {
            minm = (minm == -1) ? move : min(minm, move);
            return;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (outside(ni, nj) || grid[ni][nj] == '#')
                continue;
            if (isupper(grid[ni][nj]) && !hasKey(keys, grid[ni][nj] - 'A'))
                continue;
            dfs(ni, nj, move + 1, keys);
        }
    }

    int solve() {
        minm = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@')
                    dfs(i, j, 0, 0);
            }
        }
        return minm;
    }

public:
    int shortestPathAllKeys(vector<string>& grid) {
        init(grid);
        return solve();
    }
};
