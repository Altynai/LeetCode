using int64 = long long;

class Solution {

  int64 getSum(vector<vector<int>> &a, int n, int m) {
    int64 sum = 0;
    for (int i = 0; i < n; i++)
      sum += accumulate(a[i].begin(), a[i].end(), 0LL);
    return sum;
  }

  bool withoutDiscounting(vector<vector<int>> &a, int n, int m) {
    int64 sum = getSum(a, n, m);
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

  bool withLeftOrUpDiscounting(vector<vector<int>> &a, int n, int m) {
    int64 sum = getSum(a, n, m);
    unordered_set<int> seen;

    // horizontal
    int64 now = 0;
    for (int i = 0; i < n - 1; i++) {
      now += accumulate(a[i].begin(), a[i].end(), 0LL);
      if (i == 0)
        seen.insert(a[0][0]), seen.insert(a[0][m - 1]);
      else {
        seen.insert(a[i].begin(), a[i].end());
        if (i == 1)
          for (int x : a[0])
            seen.insert(x);
      }
      int64 other = sum - now;
      int64 y = now - other;
      if (m == 1) { // fuck this edge case
        if (y == a[0][0] or y == a[i][0])
          return 1;
      } else if (seen.find(y) != seen.end()) {
        return 1;
      }
    }

    // vertical
    now = 0;
    seen.clear();
    for (int j = 0; j < m - 1; j++) {
      for (int i = 0; i < n; i++)
        now += a[i][j];
      if (j == 0)
        seen.insert(a[0][0]), seen.insert(a[n - 1][0]);
      else {
        for (int i = 0; i < n; i++)
          seen.insert(a[i][j]);
        if (j == 1)
          for (int i = 0; i < n; i++)
            seen.insert(a[i][0]);
      }
      int64 other = sum - now;
      int64 y = now - other;
      if (n == 1) { // fuck this edge case
        if (y == a[0][0] or y == a[0][j])
          return 1;
      } else if (seen.find(y) != seen.end())
        return 1;
    }
    return 0;
  }

public:
  bool canPartitionGrid(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    if (withoutDiscounting(a, n, m) or withLeftOrUpDiscounting(a, n, m))
      return 1;

    vector<vector<int>> b = a;
    for (int i = 0; i < n; i++)
      reverse(b[i].begin(), b[i].end());
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n / 2; i++) {
        swap(b[i][j], b[n - 1 - i][j]);
      }
    }
    return withLeftOrUpDiscounting(b, n, m);
  }
};
