class Solution {
public:
  bool isZeroArray(vector<int> &a, vector<vector<int>> &queries) {
    int n = a.size(), m = queries.size();
    vector<int> sum(n, 0);

    for (int i = 0; i < m; i++) {
      int x = queries[i][0], y = queries[i][1];
      sum[x] += 1;
      if (y + 1 < n)
        sum[y + 1] -= 1;
    }

    for (int i = 0; i < n; i++) {
      if (i > 0)
        sum[i] += sum[i - 1];
      if (sum[i] < a[i])
        return 0;
    }

    return 1;
  }
};
