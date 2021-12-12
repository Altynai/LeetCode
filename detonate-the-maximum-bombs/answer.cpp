class Solution {
public:
  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    vector<vector<bool>> det(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++) {
      long long x0 = bombs[i][0], y0 = bombs[i][1], r0 = bombs[i][2];
      for (int j = 0; j < n; j++) {
        long long x1 = bombs[j][0], y1 = bombs[j][1];
        long long dx = abs(x0 - x1), dy = abs(y0 - y1);
        if (dx * dx + dy * dy <= r0 * r0)
          det[i][j] = 1;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      vector<bool> vis(n, 0);
      queue<int> que;
      que.push(i), vis[i] = 1;
      while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v = 0; v < n; v++) {
          if (u != v && det[u][v] && !vis[v])
            que.push(v), vis[v] = 1;
        }
      }
      int cnt = 0;
      for (int j = 0; j < n; j++)
        if (vis[j])
          cnt++;
      ans = max(ans, cnt);
    }
    return ans;
  }
};
