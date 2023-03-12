class Solution {
public:
  int findMinimumTime(vector<vector<int>> &tasks) {
    int n = tasks.size();
    sort(tasks.begin(), tasks.end(), [](const auto &lh, const auto &rh) {
      if (lh[1] != rh[1])
        return lh[1] < rh[1];
      return lh[0] < rh[0];
    });

    int m = tasks[n - 1][1];
    vector<bool> vis(m + 1, 0);
    for (auto &t : tasks) {
      int had = 0;
      for (int i = t[1]; i >= t[0]; i--) {
        if (vis[i])
          had++;
      }
      for (int i = t[1]; had < t[2] and i >= t[0]; i--) {
        if (!vis[i])
          vis[i] = 1, had++;
      }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
      if (vis[i])
        ans++;
    }
    return ans;
  }
};
