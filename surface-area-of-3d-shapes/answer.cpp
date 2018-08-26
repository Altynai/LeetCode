int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                ans += 2;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                        ans += grid[i][j];
                    else
                        ans += max(grid[i][j] - grid[ni][nj], 0);
                }
            }
        }
        return ans;
    }
};
