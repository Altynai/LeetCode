template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maximumLength(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    vector<int> freq(k, 0);
    for (int i = 0; i < n; i++) {
      a[i] %= k;
      umax(ans, ++freq[a[i]]);
    }

    vector<vector<int>> dp(k, vector<int>(k, 0));
    for (int i = n - 1; i >= 0; i--) {
      int x = a[i];
      for (int y = 0; y < k; y++) {
        if (y == x)
          continue;
        umax(dp[x][y], dp[y][x] + 1);
        umax(ans, dp[x][y]);
      }
    }
    return ans;
  }
};
