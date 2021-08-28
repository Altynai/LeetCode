class Solution {
public:
  int minimizeTheDifference(vector<vector<int>> &mat, int target) {
    int n = mat.size(), m = mat[0].size();

    const int maxn = 70 * 70 + 1;
    vector<bool> dp(maxn, 0);
    for (auto val : mat[0])
      dp[val] = 1;

    for (int i = 1; i < n; i++) {
      vector<bool> ndp(maxn, 0);
      for (int j = 1; j < maxn; j++) {
        if (!dp[j])
          continue;
        for (int val : mat[i]) {
          if (val + j < maxn)
            ndp[val + j] = 1;
        }
      }
      dp = ndp;
    }

    int best = INT_MAX;
    for (int i = 1; i < maxn; i++) {
      if (int d = abs(i - target); dp[i] && d < best)
        best = d;
    }
    return best;
  }
};
