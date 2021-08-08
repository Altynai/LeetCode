// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minSpaceWastedKResizing(vector<int> &a, int k) {
    int n = a.size();
    vector<int> b(a);
    sort(b.begin(), b.end());
    int m = unique(b.begin(), b.end()) - b.begin();
    b.resize(m);
    for (int i = 0; i < n; i++)
      a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    vector<vector<int>> dp(m, vector<int>(k + 1, INT_MAX));
    for (int i = a[0]; i < m; i++) {
      if (a[0] == i)
        dp[i][0] = 0;
      else
        dp[i][0] = abs(b[i] - b[a[0]]);
    }

    for (int i = 1; i < n; i++) {
      vector<vector<int>> ndp(m, vector<int>(k + 1, INT_MAX));
      // no changes
      for (int x = a[i]; x < m; x++) {
        for (int y = 0; y <= k; y++) {
          if (dp[x][y] == INT_MAX)
            continue;
          umin(ndp[x][y], dp[x][y] + abs(b[a[i]] - b[x]));
        }
      }
      // resize
      for (int y = 0; y < k; y++) {
        int best = INT_MAX;
        for (int x = 0; x < m; x++)
          umin(best, dp[x][y]);
        if (best == INT_MAX)
          continue;
        for (int x = a[i]; x < m; x++)
          umin(ndp[x][y + 1], best + abs(b[a[i]] - b[x]));
      }
      dp = ndp;
    }

    int ans = INT_MAX;
    for (int x = 0; x < m; x++)
      umin(ans, *min_element(dp[x].begin(), dp[x].end()));
    return ans;
  }
};
