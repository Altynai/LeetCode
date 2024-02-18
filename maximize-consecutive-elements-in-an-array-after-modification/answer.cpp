template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxSelectedElements(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());

    int maxVal = a[n - 1];
    vector<int> dp(maxVal + 2, 0);
    dp[a[0]] = dp[a[0] + 1] = 1;

    for (int i = 1; i < n; i++) {
      int x = 0, y = 0;
      if (dp[a[i] - 1] > 0)
        umax(x, dp[a[i] - 1] + 1);
      if (dp[a[i]] > 0)
        umax(y, dp[a[i]] + 1);

      umax(dp[a[i]], max(x, 1));
      umax(dp[a[i] + 1], max(y, 1));
    }

    return max(1, *max_element(dp.begin(), dp.end()));
  }
};
