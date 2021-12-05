template <class T> void deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &edges) {
    int m = edges.size();
    vector<int> labels;
    for (auto &e : edges)
      labels.push_back(e[0]), labels.push_back(e[1]);
    deduplicate(labels);

    int n = labels.size();
    for (auto &e : edges) {
      e[0] = lower_bound(labels.begin(), labels.end(), e[0]) - labels.begin();
      e[1] = lower_bound(labels.begin(), labels.end(), e[1]) - labels.begin();
    }

    vector<int> deg(n, 0);
    for (auto &e : edges)
      deg[e[0]]++, deg[e[1]]--;
    int start = -1;
    for (int i = 0; i < n; i++)
      if (deg[i] == 1)
        start = i;
    if (start == -1)
      start = 0;

    vector<vector<int>> adj(n);
    for (auto &e : edges)
      adj[e[0]].push_back(e[1]);

    vector<vector<int>> ans;
    function<void(int)> dfs = [&](int u) {
      while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
        ans.push_back({labels[u], labels[v]});
      }
    };
    dfs(start);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
