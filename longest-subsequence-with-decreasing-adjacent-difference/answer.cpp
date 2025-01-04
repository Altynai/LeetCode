template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int longestSubsequence(vector<int> &a) {
    // dp[i][j]: last difference is j for a[i ... n - 1]
    // dp[i][j] = max(dp[x][y] + 1), if
    //   x > i and y <= j
    //   abs(a[x] - a[i]) == j

    // oh, we can store dp[i][j]: last element is i and difference is j
    // so dp[a[i]][j] = max(dp[x][y] + 1)
    // x = a[i] - j or a[i] + j

    int n = a.size();

    int N = *max_element(a.begin(), a.end());
    vector<vector<int>> dp(N + 1, vector<int>(N, -1));

    int ans = 2;
    set<int> seen;
    for (int i = n - 1; i >= 0; i--) {
      // speed-up: since we only need to update dp[i] with old dp value
      vector<int> f = dp[a[i]];

      for (int j = 0; j < N; j++) {
        int x = a[i] - j;
        if (x >= 0 and x <= N and dp[x][j] != -1) {
          umax(f[j], dp[x][j] + 1);
        }
        x = a[i] + j;
        if (x >= 0 and x <= N and dp[x][j] != -1) {
          umax(f[j], dp[x][j] + 1);
        }
      }
      auto it = seen.lower_bound(a[i]);
      if (it != seen.end())
        umax(f[abs(a[i] - *it)], 2);
      if (it != seen.begin()) {
        it = prev(it);
        umax(f[abs(a[i] - *it)], 2);
      }

      for (int j = 1; j < N; j++)
        umax(f[j], f[j - 1]);
      umax(ans, f[N - 1]);

      dp[a[i]] = f;
      seen.insert(a[i]);
    }
    return ans;
  }
};
