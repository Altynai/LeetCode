const int N = 10;

class Solution {
public:
  int minimumOperations(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> dp(N, 0);
    for (int j = 0; j < m; j++) {
      vector<int> cnt(N, 0);
      for (int i = 0; i < n; i++)
        cnt[a[i][j]]++;

      vector<int> ndp(N, INT_MAX);
      for (int k = 0; k < N; k++) {
        int changes = n - cnt[k];
        for (int z = 0; z < N; z++) {
          if (z == k)
            continue;
          ndp[k] = min(ndp[k], dp[z] + changes);
        }
      }

      swap(dp, ndp);
    }
    return *min_element(dp.begin(), dp.end());
  }
};
