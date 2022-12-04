struct BipartiteChecker {

  pair<bool, vector<int>> isBipartite(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
      if (color[i] != -1)
        continue;

      color[i] = 0;
      deque<int> q = {i};
      while (q.size()) {
        int u = q.front();
        q.pop_front();

        int nc = color[u] ^ 1;
        for (int v : g[u]) {
          if (color[v] == -1) {
            color[v] = nc;
            q.push_back(v);
          } else if (color[v] != nc)
            return {false, {}};
        }
      }
    }
    return {true, color};
  }

} bipartite_checker;

class Solution {
public:
  int magnificentSets(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if (!bipartite_checker.isBipartite(adj).first)
      return -1;

    auto countGroup = [&](const vector<int> &a) -> int {
      int best = 0;
      vector<int> dis(n, -1);

      for (int x : a) {
        dis.assign(n, -1);
        deque<int> q = {x};
        dis[x] = 1;
        while (q.size()) {
          int u = q.front();
          q.pop_front();

          for (int v : adj[u]) {
            if (dis[v] == -1) {
              dis[v] = dis[u] + 1;
              q.push_back(v);
            }
          }
        }
        best = max(best, *max_element(dis.begin(), dis.end()));
      }
      return best;
    };

    // find components
    vector<bool> vis(n, 0);
    function<void(int u, vector<int> &)> dfs = [&](int u, vector<int> &res) {
      vis[u] = 1;
      res.push_back(u);
      for (int v : adj[u]) {
        if (!vis[v])
          dfs(v, res);
      }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        vector<int> res;
        dfs(i, res);
        ans += countGroup(res);
      }
    }
    return ans;
  }
};
