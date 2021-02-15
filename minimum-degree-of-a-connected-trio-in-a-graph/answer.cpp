class Solution {
public:
  int minTrioDegree(int n, vector<vector<int>> &edges) {
    vector<vector<bool>> path(n, vector<bool>(n, false));
    vector<int> deg(n, 0);

    for (auto &e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      path[u][v] = true;
      path[v][u] = true;
      deg[u]++;
      deg[v]++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!path[i][j])
          continue;

        for (int k = 0; k < n; k++) {
          if (path[i][k] && path[j][k])
            ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
