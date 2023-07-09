template <class T> bool umax(T &a, const T b) { return b > a ? a = b, 1 : 0; }

class Solution {
public:
  int maximumJumps(vector<int> &a, int target) {
    int n = a.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] != -1 and abs(a[i] - a[j]) <= target)
          umax(dp[i], dp[j] + 1);
      }
    }
    return dp[n - 1];
  }
};
