class Solution {
public:
  int matrixSum(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    for (auto &row : a)
      sort(row.begin(), row.end());

    int ans = 0;
    for (int j = m - 1; j >= 0; j--) {
      int x = a[0][j];
      for (int i = 1; i < n; i++)
        x = max(a[i][j], x);
      ans += x;
    }
    return ans;
  }
};
