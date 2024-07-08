class Solution {
private:
  vector<vector<int>> count(const vector<vector<char>> &g, char ch) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i > 0)
          cnt[i][j] += cnt[i - 1][j];
        if (j > 0)
          cnt[i][j] += cnt[i][j - 1];
        if (i > 0 and j > 0)
          cnt[i][j] -= cnt[i - 1][j - 1];
        if (g[i][j] == ch)
          cnt[i][j]++;
      }
    }
    return cnt;
  }

public:
  int numberOfSubmatrices(vector<vector<char>> &g) {
    int n = g.size(), m = g[0].size();
    vector<vector<int>> x = count(g, 'X');
    vector<vector<int>> y = count(g, 'Y');

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (x[i][j] > 0 and x[i][j] == y[i][j])
          ans++;
      }
    }
    return ans;
  }
};
