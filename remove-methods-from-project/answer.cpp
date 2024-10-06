class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    vector<vector<int>> adj(n);
    for (auto edge : invocations)
      adj[edge[0]].push_back(edge[1]);

    vector<bool> marked(n, 0);
    function<void(int)> dfs = [&](int u) {
      marked[u] = 1;
      for (int v : adj[u]) {
        if (!marked[v])
          dfs(v);
      }
    };
    dfs(k);

    for (auto edge : invocations) {
      if (!marked[edge[0]] and marked[edge[1]]) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        return p;
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (!marked[i])
        ans.push_back(i);
    }
    return ans;
  }
};
