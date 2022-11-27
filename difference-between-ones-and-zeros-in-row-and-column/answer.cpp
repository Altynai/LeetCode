class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> row(2, vector<int>(n, 0));
    vector<vector<int>> col(2, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        row[a[i][j]][i]++;
        col[a[i][j]][j]++;
      }
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans[i][j] = row[1][i] + col[1][j] - row[0][i] - col[0][j];
      }
    }
    return ans;
  }
};
