template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  bool good(char a, char b) {
    if (a > b)
      swap(a, b);
    if (b - a == 1)
      return 1;
    return a == 'a' and b == 'z';
  }

  string lexicographicallySmallestString(string s) {
    int n = s.size();

    // 0: substring can not be removed
    // 1: substring can be removed
    vector<vector<int>> can(n, vector<int>(n, -1));
    function<int(int, int)> dfs = [&](int l, int r) -> int {
      if (l > r)
        return 1;
      if (can[l][r] != -1)
        return can[l][r];

      int m = r - l + 1;
      if (m % 2 == 1)
        return can[l][r] = 0;

      if (good(s[l], s[r]) and dfs(l + 1, r - 1))
        return can[l][r] = 1;
      for (int i = l + 1; i < r; i += 2) {
        if (dfs(l, i) and dfs(i + 1, r))
          return can[l][r] = 1;
      }
      return can[l][r] = 0;
    };

    vector<string> dp(n + 1);
    for (int i = 0; i < n; i++)
      dp[i] = s.substr(i);
    dp[n] = "";

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = s.substr(i, 1) + dp[i + 1];
      for (int j = i; j <= n - 1; j++) {
        if (dfs(i, j) == 1)
          umin(dp[i], dp[j + 1]);
      }
    }
    return dp[0];
  }
};
