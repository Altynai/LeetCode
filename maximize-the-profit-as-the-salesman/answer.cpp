template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maximizeTheProfit(int n, vector<vector<int>> &offers) {
    int m = offers.size();
    sort(offers.begin(), offers.end(), [](auto &lh, auto &rh) {
      if (lh[1] != rh[1])
        return lh[1] < rh[1];
      return lh[0] < rh[0];
    });

    vector<int> dp(n + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      umax(dp[i], dp[i - 1]);
      while (j < m and i > offers[j][1] + 1)
        j++;
      while (j < m and i == offers[j][1] + 1)
        umax(dp[i], dp[offers[j][0]] + offers[j++][2]);
    }
    return dp[n];
  }
};
