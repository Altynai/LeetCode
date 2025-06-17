template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maximumProfit(vector<int> &p, int k) {
    // dp[i][j][state]: max profit after day i with j transactions compeleted,
    // remain state (0: free, 1: in normal, 2: in short)

    int n = p.size();
    vector<vector<vector<int64>>> dp(
        n, vector<vector<int64>>(k + 1, vector<int64>(3, -1)));

    const int64 BAD = LLONG_MIN;

    function<int64(int, int, int)> dfs = [&](int pos, int txn,
                                             int state) -> int64 {
      if (txn > k)
        return BAD;
      if (pos == n)
        return state == 0 ? 0 : BAD;

      int64 &res = dp[pos][txn][state];
      if (res != -1)
        return res;

      res = BAD;
      // skip pos
      int64 got = dfs(pos + 1, txn, state);
      if (got != BAD)
        umax(res, got);

      // start new transaction
      if (state == 0) {
        got = dfs(pos + 1, txn, 1);
        if (got != BAD)
          umax(res, -p[pos] + got);
        got = dfs(pos + 1, txn, 2);
        if (got != BAD)
          umax(res, +p[pos] + got);
      }

      // normal
      if (state == 1) {
        got = dfs(pos + 1, txn + 1, 0);
        if (got != BAD)
          umax(res, +p[pos] + got);
      }

      // short
      if (state == 2) {
        got = dfs(pos + 1, txn + 1, 0);
        if (got != BAD)
          umax(res, -p[pos] + got);
      }

      return res;
    };

    int64 ans = dfs(1, 0, 0);
    int64 got = dfs(1, 0, 1);
    if (got != BAD)
      umax(ans, -p[0] + got);
    got = dfs(1, 0, 2);
    if (got != BAD)
      umax(ans, +p[0] + got);
    return ans;
  }
};
