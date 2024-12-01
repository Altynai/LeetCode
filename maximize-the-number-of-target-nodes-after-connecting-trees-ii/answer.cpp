class Solution {
private:
  vector<int> distance(const vector<vector<int>> &edges) {
    int m = edges.size();
    vector<vector<int>> adj(m + 1);
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> dis(m + 1);
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
      dis[u] = d;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u, d ^ 1);
      }
    };
    dfs(0, -1, 0);
    return dis;
  }

public:
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2) {
    int n = edges1.size() + 1, m = edges2.size() + 1;
    vector<int> d1 = distance(edges1), d2 = distance(edges2);

    vector<int> cnt1(2, 0), cnt2(2, 0);
    for (int x : d1)
      cnt1[x]++;
    for (int x : d2)
      cnt2[x]++;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = cnt1[d1[i]] + max(cnt2[0], cnt2[1]);
    }
    return ans;
  }
};
