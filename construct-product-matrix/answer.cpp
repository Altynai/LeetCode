const int MOD = 12345;

class Solution {
public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    vector<vector<int>> suffix(n, vector<int>(m, 0));
    int y = 1;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        a[i][j] %= MOD;
        y = 1LL * y * a[i][j] % MOD;
        suffix[i][j] = y;
      }
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));
    int x = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j == m - 1)
          y = (i == n - 1 ? 1 : suffix[i + 1][0]);
        else
          y = suffix[i][j + 1];

        ans[i][j] = 1LL * x * y % MOD;
        x = 1LL * x * a[i][j] % MOD;
      }
    }
    return ans;
  }
};
