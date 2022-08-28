struct TopologicalSort {
  // order, {} means there is cycle
  vector<int> findOrder(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> deg(n, 0);
    for (int u = 0; u < n; u++)
      for (int v : g[u])
        deg[v]++;

    deque<int> q;
    for (int u = 0; u < n; u++)
      if (deg[u] == 0)
        q.push_back(u);

    vector<int> ord(n, -1);
    int timestamp = 0;
    while (q.size()) {
      int u = q.front();
      q.pop_front();
      ord[u] = timestamp++;
      for (int v : g[u]) {
        if (--deg[v] == 0)
          q.push_back(v);
      }
    }

    // found cycle
    if (timestamp < n)
      return {};
    return ord;
  }
} topological_sort;

class Solution {
public:
  vector<int> findIndex(int k, const vector<vector<int>> &c) {
    vector<vector<int>> adj(k);
    for (auto p : c)
      adj[p[1] - 1].push_back(p[0] - 1);
    return topological_sort.findOrder(adj);
  }

  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    vector<int> r = findIndex(k, rowConditions);
    if (r.empty())
      return {};

    vector<int> c = findIndex(k, colConditions);
    if (c.empty())
      return {};

    vector<vector<int>> ans(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++)
      ans[k - 1 - r[i]][k - 1 - c[i]] = i + 1;
    return ans;
  }
};
