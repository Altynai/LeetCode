using int64 = long long;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  long long maximumOr(vector<int> &a, int k) {
    int n = a.size();
    vector<int64> dp(k + 1, 0);
    for (int i = 0; i < n; i++) {
      vector<int64> ndp = dp;
      for (int j = 0; j <= k; j++) {
        for (int x = 0; x <= j; x++) {
          umax(ndp[j], dp[j - x] | ((1LL * a[i]) << x));
        }
      }
      dp = ndp;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
