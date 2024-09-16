template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maxScore(vector<int> &a, vector<int> &b) {
    int n = b.size();

    vector<int64> dp(5, LLONG_MIN);
    dp[0] = 0;

    int64 ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
      vector<int64> ndp = dp;
      for (int j = 1; j <= 4; j++) {
        if (dp[j - 1] != LLONG_MIN) {
          umax(ndp[j], dp[j - 1] + 1LL * a[j - 1] * b[i]);
        }
      }
      umax(ans, ndp[4]);
      swap(dp, ndp);
    }
    return ans;
  }
};
