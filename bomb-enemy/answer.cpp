class Solution {
public:
    vector<vector<int>> counter;
    int n, m;
    void init(vector<vector<char>>& grid) {
        n = grid.size();
        m = (n > 0) ? grid[0].size() : 0;
        counter = vector<vector<int>>(n, vector<int>(m, 0));
    }

    void iterRows(int columnStart, int columnEnd, vector<vector<char>>& grid) {
        int step = (columnStart <= columnEnd) ? 1 : -1;
        for (int i = 0; i < n; ++i) {
            int enemy = 0;
            for (int j = columnStart; j != columnEnd; j += step) {
                if (grid[i][j] == 'E')
                    enemy++;
                else if (grid[i][j] == 'W')
                    enemy = 0;
                else
                    counter[i][j] += enemy;
            }
        }
    }

    void iterColumns(int rowStart, int rowEnd, vector<vector<char>>& grid) {
        int step = (rowStart <= rowEnd) ? 1 : -1;
        for (int j = 0; j < m; ++j) {
            int enemy = 0;
            for (int i = rowStart; i != rowEnd; i += step) {
                if (grid[i][j] == 'E')
                    enemy++;
                else if (grid[i][j] == 'W')
                    enemy = 0;
                else
                    counter[i][j] += enemy;
            }
        }
    }

    int findMax() {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = max(ans, counter[i][j]);
            }
        }
        return ans;
    }

    int maxKilledEnemies(vector<vector<char>>& grid) {
        init(grid);
        iterRows(0, m, grid);
        iterRows(m - 1, -1, grid);
        iterColumns(0, n, grid);
        iterColumns(n - 1, -1, grid);
        return findMax();
    }
};