class Solution {
public:
  int minPathCost(vector<vector<int>> &a, vector<vector<int>> &moveCost) {
    int n = a.size(), m = a[0].size();
    vector<int> dp = a[0];

    for (int i = 1; i < n; i++) {
      vector<int> ndp(m, INT_MAX);
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          int cost = dp[j] + moveCost[a[i - 1][j]][k] + a[i][k];
          ndp[k] = min(cost, ndp[k]);
        }
      }
      swap(dp, ndp);
    }
    return *min_element(dp.begin(), dp.end());
  }
};
