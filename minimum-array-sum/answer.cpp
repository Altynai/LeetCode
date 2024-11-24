template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minArraySum(vector<int> &a, int k, int op1, int op2) {
    // dp[i][x][y]: minimum sum after processing a[0 ... i] with x times op1 and
    // y times op2 transition? do op1 or not, same for op2, can be combined

    int n = a.size();
    vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
      vector<vector<int>> ndp(op1 + 1, vector<int>(op2 + 1, INT_MAX));
      for (int x = 0; x <= min(op1, i + 1); x++) {
        for (int y = 0; y <= min(op2, i + 1); y++) {

          int rd = (a[i] + 1) / 2;
          // do nothing
          if (dp[x][y] != INT_MAX)
            umin(ndp[x][y], dp[x][y] + a[i]);
          // op1
          if (x > 0 and dp[x - 1][y] != INT_MAX)
            umin(ndp[x][y], dp[x - 1][y] + rd);
          // op2
          if (y > 0 and dp[x][y - 1] != INT_MAX and a[i] >= k)
            umin(ndp[x][y], dp[x][y - 1] + (a[i] - k));
          // op1 + op2
          if (x > 0 and y > 0 and dp[x - 1][y - 1] != INT_MAX and rd >= k)
            umin(ndp[x][y], dp[x - 1][y - 1] + (rd - k));
          // op2 + op1
          if (x > 0 and y > 0 and dp[x - 1][y - 1] != INT_MAX and a[i] >= k)
            umin(ndp[x][y], dp[x - 1][y - 1] + (a[i] - k + 1) / 2);
        }
      }
      swap(dp, ndp);
    }

    int ans = INT_MAX;
    for (int x = 0; x <= op1; x++) {
      for (int y = 0; y <= op2; y++)
        umin(ans, dp[x][y]);
    }
    return ans;
  }
};
