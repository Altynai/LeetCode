const int N = 26;

class Solution {
public:
  int maxPointsInsideSquare(vector<vector<int>> &p, string s) {
    int n = p.size(), ans = 0;
    for (int l = 0, r = 1e9; l <= r;) {
      int mid = (l + r) / 2;
      vector<bool> vis(N, 0);
      bool ok = 1;
      int cnt = 0;
      for (int i = 0; ok and i < n; i++) {
        if (abs(p[i][0]) <= mid and abs(p[i][1]) <= mid) {
          int k = s[i] - 'a';
          if (vis[k])
            ok = 0;
          else
            vis[k] = 1, cnt++;
        }
      }
      if (ok)
        l = mid + 1, ans = max(ans, cnt);
      else
        r = mid - 1;
    }
    return ans;
  }
};
