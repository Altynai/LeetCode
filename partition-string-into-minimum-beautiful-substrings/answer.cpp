template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minimumBeautifulSubstrings(string s) {
    if (s[0] == '0')
      return -1;

    int n = s.size();
    const int M = 1 << n;

    vector<bool> good(M, 0);
    for (int i = 1; i < M; i *= 5)
      good[i] = 1;

    vector<int> dp(M, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      vector<int> ndp(M, INT_MAX);
      for (int j = 0; j < M; j++) {
        if (dp[j] == INT_MAX)
          continue;
        int x = (j << 1) + (s[i] - '0');
        umin(ndp[x], dp[j]);
        if (good[x] and (i == n - 1 or s[i + 1] == '1'))
          umin(ndp[0], dp[j] + 1);
      }
      swap(dp, ndp);
    }
    return dp[0] == INT_MAX ? -1 : dp[0];
  }
};
