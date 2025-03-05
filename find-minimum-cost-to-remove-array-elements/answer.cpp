template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
private:
  int last3(int x, int y, int z) {
    int res = INT_MAX;
    umin(res, max(x, y) + z);
    umin(res, max(x, z) + y);
    umin(res, max(y, z) + x);
    return res;
  }

public:
  int minCost(vector<int> &a) {
    // dp[i][j]: j is the left one after processing [0 ... i]
    // we can make transition to dp[i + 2][?] in O(1)

    int n = a.size();
    if (n == 1)
      return a[0];
    if (n == 2)
      return max(a[0], a[1]);
    if (n == 3)
      return last3(a[0], a[1], a[2]);

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    dp[2][0] = max(a[1], a[2]);
    dp[2][1] = max(a[0], a[2]);
    dp[2][2] = max(a[0], a[1]);

    int i;
    for (i = 2; i + 2 < n - 1; i += 2) {
      for (int j = 0; j <= i; j++) {
        // j, i + 1, i + 2
        umin(dp[i + 2][j], dp[i][j] + max(a[i + 1], a[i + 2]));
        umin(dp[i + 2][i + 1], dp[i][j] + max(a[j], a[i + 2]));
        umin(dp[i + 2][i + 2], dp[i][j] + max(a[j], a[i + 1]));
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j <= i; j++) {
      if (i == n - 3)
        umin(ans, dp[i][j] + last3(a[j], a[n - 1], a[n - 2]));
      else if (i == n - 2)
        umin(ans, dp[i][j] + max(a[j], a[n - 1]));
      else
        umin(ans, dp[i][j]);
    }
    return ans;
  }
};
