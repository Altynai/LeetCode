template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  vector<int> maximumSubarrayXor(vector<int> &a, vector<vector<int>> &queries) {
    // Key Observation: dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1]
    int n = a.size(), m = queries.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (i == j)
          dp[i][j] = a[i];
        else if (i + 1 == j)
          dp[i][j] = (a[i] ^ a[j]);
        else
          dp[i][j] = dp[i + 1][j] ^ dp[i][j - 1];
      }
    }

    vector<array<int, 3>> v(m);
    for (int i = 0; i < m; i++)
      v[i] = {queries[i][0], queries[i][1], i};
    sort(v.begin(), v.end(), [](auto &lh, auto &rh) {
      if (lh[1] != rh[1])
        return lh[1] < rh[1];
      return lh[0] > rh[0];
    });

    vector<int> ans(m, 0);
    vector<int> best = a;
    for (int r = 0, j = 0; r < n; r++) {
      for (int l = r; l >= 0; l--) {
        umax(best[l], dp[l][r]);
        if (l < r)
          umax(best[l], best[l + 1]);
      }
      while (j < m and v[j][1] == r) {
        ans[v[j][2]] = best[v[j][0]];
        j++;
      }
    }
    return ans;
  }
};
