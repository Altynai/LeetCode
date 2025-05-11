using int64 = long long;

class Solution {
public:
  bool canPartitionGrid(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int64 sum = 0;
    for (int i = 0; i < n; i++)
      sum += accumulate(a[i].begin(), a[i].end(), 0LL);

    if (sum & 1)
      return 0;

    // horizontal
    int64 now = 0;
    for (int i = 0; i < n - 1; i++) {
      now += accumulate(a[i].begin(), a[i].end(), 0LL);
      if (now == sum / 2)
        return 1;
    }

    // vertical
    now = 0;
    for (int j = 0; j < m - 1; j++) {
      for (int i = 0; i < n; i++)
        now += a[i][j];
      if (now == sum / 2)
        return 1;
    }
    return 0;
  }
};
