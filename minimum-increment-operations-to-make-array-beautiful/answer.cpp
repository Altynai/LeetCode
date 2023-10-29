template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long minIncrementOperations(vector<int> &a, int k) {
    int n = a.size();
    vector<int64> dp(3);
    for (int i = 0; i < 3; i++)
      dp[i] = max(0, k - a[2 - i]);

    for (int i = 3; i < n; i++) {
      vector<int64> ndp(3, LLONG_MAX);
      // choose
      for (int j = 0; j < 3; j++) {
        umin(ndp[0], dp[j] + max(0, k - a[i]));
      }
      // skip
      for (int j = 1; j < 3; j++) {
        umin(ndp[j], dp[j - 1]);
      }
      swap(dp, ndp);
    }
    return *min_element(dp.begin(), dp.end());
  }
};
