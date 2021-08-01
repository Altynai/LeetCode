void add(int &x, int y) {
  x += y;
  x %= 1000000007;
}

class Solution {
public:
  int countSpecialSubsequences(vector<int> &a) {
    int n = a.size();
    vector<int> dp(3, 0);
    if (a[0] == 0)
      dp[0] = 1;
    for (int i = 1; i < n; i++) {
      vector<int> ndp = dp;
      if (a[i] == 0) {
        add(ndp[0], dp[0]);
        add(ndp[0], 1);
      } else if (a[i] == 1) {
        add(ndp[1], dp[0]);
        add(ndp[1], dp[1]);
      } else if (a[i] == 2) {
        add(ndp[2], dp[1]);
        add(ndp[2], dp[2]);
      }
      dp = ndp;
    }
    return dp[2];
  }
};
