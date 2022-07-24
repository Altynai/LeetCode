class Solution {
public:
  int equalPairs(vector<vector<int>> &a) {
    int ans = 0, n = a.size();
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        bool ok = 1;
        for (int i = 0; ok and i < n; i++) {
          if (a[r][i] != a[i][c])
            ok = 0;
        }
        if (ok)
          ans++;
      }
    }
    return ans;
  }
};
