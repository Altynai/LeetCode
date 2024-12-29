class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int ans = 0, n = grid.size(), m = grid[0].size();
    for (int j = 0; j < m; j++) {
      for (int i = 1; i < n; i++) {
        int val = grid[i - 1][j] + 1;
        if (grid[i][j] < val) {
          ans += val - grid[i][j];
          grid[i][j] = val;
        }
      }
    }
    return ans;
  }
};
