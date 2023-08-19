template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minimumOperations(vector<int> &a) {
    int n = a.size();
    vector<int> dp(4, INT_MAX);
    dp[1] = 0;

    for (int i = 0; i < n; i++) {
      vector<int> ndp(4, INT_MAX);

      for (int j = 1; j <= 3; j++) {
        if (dp[j] == INT_MAX)
          continue;
        for (int k = j; k <= 3; k++)
          umin(ndp[k], dp[j] + (k == a[i] ? 0 : 1));
      }
      swap(dp, ndp);
    }
    return *min_element(dp.begin(), dp.end());
  }
};
