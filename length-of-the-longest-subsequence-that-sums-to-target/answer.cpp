template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int lengthOfLongestSubsequence(vector<int> &a, int target) {
    int n = a.size();
    vector<int> dp(target + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
      vector<int> ndp = dp;
      for (int j = 0; j + a[i - 1] <= target; j++) {
        if (dp[j] == -1)
          continue;
        // choose
        umax(ndp[j + a[i - 1]], dp[j] + 1);
      }
      swap(dp, ndp);
    }
    return dp[target];
  }
};
