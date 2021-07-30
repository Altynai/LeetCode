// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int maxCompatibilitySum(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size(), m = a[0].size();
    vector<int> dp(1 << n, 0);

    auto score = [&](int x, int y) -> int {
      int ans = 0;
      for (int j = 0; j < m; j++)
        if (a[x][j] == b[y][j])
          ans++;
      return ans;
    };

    for (int j = 0; j < n; j++)
      dp[1 << j] = score(0, j);

    for (int i = 1; i < n; i++) {
      vector<int> ndp(1 << n, 0);
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int k = 0; k < n; k++) {
          if (mask & (1 << k))
            continue;
          umax(ndp[mask | (1 << k)], dp[mask] + score(i, k));
        }
      }
      dp = ndp;
    }
    return dp[(1 << n) - 1];
  }
};
