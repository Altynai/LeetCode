class Solution {
public:
  int sumImbalanceNumbers(vector<int> &a) {
    int n = a.size(), ans = 0;
    vector<bool> vis(n + 1, 0);
    vector<bool> good(n + 1, 0);
    for (int i = 0; i < n; i++) {
      vis.assign(n + 1, 0);
      good.assign(n + 1, 0);
      int cnt = 0;
      for (int j = i; j < n; j++) {
        if (!vis[a[j]]) {
          vis[a[j]] = good[a[j]] = 1;
          cnt++;

          // forwards
          int x = a[j] + 1;
          if (x <= n and vis[x] and good[a[j]])
            good[a[j]] = 0, cnt--;
          // backwards
          x = a[j] - 1;
          if (x >= 1 and vis[x] and good[x])
            good[x] = 0, cnt--;
        }
        ans += cnt - 1;
      }
    }
    return ans;
  }
};
