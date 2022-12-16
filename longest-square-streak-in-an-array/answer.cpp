class Solution {
public:
  int longestSquareStreak(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size(), ans = 0;
    map<int, int> dp;
    for (int i = 0; i < n; i++) {
      int x = (int)sqrt(1.0 * a[i]);
      if (x * x == a[i])
        ans = max(ans, dp[a[i]] = dp[x] + 1);
      else
        dp[a[i]] = 1;
    }
    return ans >= 2 ? ans : -1;
  }
};
