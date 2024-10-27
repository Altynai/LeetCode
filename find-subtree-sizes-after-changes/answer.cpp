const int N = 26;

class Solution {
public:
  vector<int> findSubtreeSizes(vector<int> &parent, string s) {
    vector<vector<int>> last(N);
    int n = s.size();

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
      adj[parent[i]].push_back(i);

    function<void(int)> dfs = [&](int u) {
      int idx = s[u] - 'a';
      if (last[idx].size() > 0)
        parent[u] = last[idx].back();

      last[idx].push_back(u);
      for (int v : adj[u])
        dfs(v);
      last[idx].pop_back();
    };
    dfs(0);

    adj = vector<vector<int>>(n);
    for (int i = 1; i < n; i++)
      adj[parent[i]].push_back(i);

    vector<int> ans(n, 0);
    function<void(int)> dfs2 = [&](int u) {
      ans[u] = 1;
      for (int v : adj[u]) {
        dfs2(v);
        ans[u] += ans[v];
      }
    };
    dfs2(0);
    return ans;
  }
};
