class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    vector<vector<bool>> roads(n, vector<bool>(n, 0));
    for (auto e : edges)
      roads[e[0]][e[1]] = roads[e[1]][e[0]] = 1;

    vector<int> component;
    auto isComplete = [&]() -> int {
      int m = component.size();
      for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
          if (!roads[component[i]][component[j]])
            return 0;
        }
      }
      return 1;
    };
    vector<bool> vis(n, 0);

    function<void(int)> dfs = [&](int u) {
      component.push_back(u);
      vis[u] = 1;
      for (int v = 0; v < n; v++) {
        if (roads[u][v] and !vis[v])
          dfs(v);
      }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        component.clear();
        dfs(i);
        ans += isComplete();
      }
    }
    return ans;
  }
};
