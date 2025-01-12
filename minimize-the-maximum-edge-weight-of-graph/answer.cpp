template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
private:
  bool check(int n, vector<vector<int>> &edges, int threshold, int max_weight) {
    vector<vector<int>> adj(n);
    for (auto &edge : edges) {
      if (edge[2] > max_weight)
        continue;
      adj[edge[1]].push_back(edge[0]);
    }

    vector<bool> vis(n, 0);
    vector<int> deg(n, 0);
    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      for (int v : adj[u]) {
        if (!vis[v]) {
          deg[v]++;
          dfs(v);
        }
      }
    };
    dfs(0);

    for (int i = 0; i < n; i++) {
      if (!vis[i] or deg[i] > threshold)
        return 0;
    }
    return 1;
  }

public:
  int minMaxWeight(int n, vector<vector<int>> &edges, int threshold) {
    int l = 1, r = 0;
    for (auto &edge : edges)
      umax(r, edge[2]);

    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(n, edges, threshold, mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
