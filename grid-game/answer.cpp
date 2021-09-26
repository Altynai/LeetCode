class Solution {
public:
  long long gridGame(vector<vector<int>> &a) {
    int m = a[0].size();
    vector<long long> sum(2, 0);
    for (int i = 0; i < 2; i++)
      sum[i] += accumulate(a[i].begin(), a[i].end(), 0LL);

    vector<long long> prefix(2, 0);
    long long ans = LLONG_MAX;
    for (int j = 0; j < m; j++) {
      long long row0 = sum[0] - (prefix[0] + a[0][j]);
      long long row1 = prefix[1];
      ans = min(ans, max(row0, row1));

      prefix[0] += a[0][j];
      prefix[1] += a[1][j];
    }
    return ans;
  }
};
