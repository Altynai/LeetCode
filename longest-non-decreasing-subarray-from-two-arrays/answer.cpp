template <class T> bool umax(T &a, const T b) { return b > a ? a = b, 1 : 0; }

class Solution {
public:
  int maxNonDecreasingLength(vector<int> &a, vector<int> &b) {
    int n = a.size(), ans = 1;
    vector<int> dp(2, 1);
    for (int i = 1; i < n; i++) {
      vector<int> ndp(2, 1);
      if (a[i] >= a[i - 1])
        umax(ndp[0], dp[0] + 1);
      if (a[i] >= b[i - 1])
        umax(ndp[0], dp[1] + 1);
      if (b[i] >= a[i - 1])
        umax(ndp[1], dp[0] + 1);
      if (b[i] >= b[i - 1])
        umax(ndp[1], dp[1] + 1);
      swap(dp, ndp);
      umax(ans, max(dp[0], dp[1]));
    }
    return ans;
  }
};
