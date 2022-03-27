template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    int n = piles.size();
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
      int m = piles[i].size();
      vector<int> ndp = dp;

      int sum = 0;
      for (int j = 1; j <= m; j++) {
        sum += piles[i][j - 1];
        for (int x = j; x <= k; x++)
          umax(ndp[x], dp[x - j] + sum);
      }
      dp = ndp;
    }
    return dp[k];
  }
};
