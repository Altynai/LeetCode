#define maxn 1002
int dp[maxn][maxn];
int sum[maxn];

int dfs(int l, int r) {
  if (dp[l][r] != -1)
    return dp[l][r];

  if (l == r)
    return dp[l][r] = 0;

  int d = sum[r] - sum[l] - dfs(l + 1, r);
  int d2 = sum[r - 1] - sum[l - 1] - dfs(l, r - 1);
  return dp[l][r] = max(d, d2);
};

class Solution {
public:
  int stoneGameVII(vector<int> &a) {
    int n = a.size();
    memset(dp, -1, sizeof(dp));
    sum[0] = 0;
    for (int i = 0; i < n; i++)
      sum[i + 1] = sum[i] + a[i];
    return dfs(1, n);
  }
};
