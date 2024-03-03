class Solution {
public:
  int countSubmatrices(vector<vector<int>> &g, int k) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> psum(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      psum[i][0] = g[i][0];
      for (int j = 1; j < m; j++)
        psum[i][j] = psum[i][j - 1] + g[i][j];
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
      int total = 0;
      for (int i = 0; i < n; i++) {
        total += psum[i][j];
        if (total <= k)
          ans++;
        else
          break;
      }
    }
    return ans;
  }
};
