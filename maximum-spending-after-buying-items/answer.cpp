using int64 = long long;

class Solution {
public:
  long long maxSpending(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> pos(n, 0);
    int64 ans = 0;
    for (int d = n * m; d > 0; d--) {
      int p = -1;
      for (int i = 0; i < n; i++) {
        if (pos[i] == m)
          continue;
        if (p == -1 or a[i][pos[i]] > a[p][pos[p]])
          p = i;
      }
      ans += 1LL * d * a[p][pos[p]];
      pos[p]++;
    }
    return ans;
  }
};
