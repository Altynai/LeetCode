template <class T> inline bool umax(T &a, const T b) {
  return b > a ? a = b, 1 : 0;
}

const int N = 101;
int dp[N][N][N];

class Solution {
public:
  int removeBoxes(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          dp[i][j][k] = -1;

    function<int(int, int, int)> dfs = [&](int l, int r, int k) -> int {
      if (l > r)
        return 0;
      else if (dp[l][r][k] != -1)
        return dp[l][r][k];
      else if (l == r)
        return dp[l][r][k] = (k + 1) * (k + 1);

      // there are k values to the left side of a[l] which is equal to a[l]
      int &ans = dp[l][r][k];

      // remove a[l]
      umax(ans, dfs(l + 1, r, 0) + (k + 1) * (k + 1));

      for (int i = l + 1; i <= r; i++) {
        if (a[l] == a[i])
          umax(ans, dfs(l + 1, i - 1, 0) + dfs(i, r, k + 1));
      }
      return ans;
    };
    return dfs(0, n - 1, 0);
  }
};
