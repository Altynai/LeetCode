class Solution {
public:
  int countGoodNodes(vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int ans = 0;
    function<int(int, int)> dfs = [&](int u, int fa) -> int {
      int p = -1, cnt = 1;
      bool good = 1;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        int res = dfs(v, u);
        if (p == -1)
          p = res;
        else if (p != res)
          good = 0;
        cnt += res;
      }
      if (good)
        ans++;
      return cnt;
    };
    dfs(0, -1);
    return ans;
  }
};
