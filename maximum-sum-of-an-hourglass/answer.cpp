class Solution {
public:
  int maxSum(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        int sum = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1];
        sum += a[i][j];
        sum += a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
        ans = max(sum, ans);
      }
    }
    return ans;
  }
};
