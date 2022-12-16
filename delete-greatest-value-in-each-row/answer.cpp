class Solution {
public:
  int deleteGreatestValue(vector<vector<int>> &a) {
    for (auto &row : a)
      sort(row.begin(), row.end());

    int n = a.size(), m = a[0].size(), sum = 0;
    for (int j = 0; j < m; j++) {
      int x = a[0][j];
      for (int i = 1; i < n; i++)
        x = max(x, a[i][j]);
      sum += x;
    }
    return sum;
  }
};
