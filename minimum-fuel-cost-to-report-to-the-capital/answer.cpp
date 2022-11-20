using int64 = long long;

class Solution {
public:
  int64 minimumFuelCost(vector<vector<int>> &roads, int seats) {
    int n = roads.size() + 1;

    vector<vector<int>> adj(n);
    for (auto &r : roads) {
      adj[r[0]].push_back(r[1]);
      adj[r[1]].push_back(r[0]);
    }

    int64 ans = 0;
    function<pair<int, int>(int, int)> dfs = [&](int u,
                                                 int fa) -> pair<int, int> {
      int full = 0, space = 1;
      for (int v : adj[u]) {
        if (v == fa)
          continue;

        auto [f, s] = dfs(v, u);
        ans += f;
        if (s > 0)
          ans++;

        full += f;
        space += s;
      }

      full += space / seats;
      space %= seats;
      return {full, space};
    };
    dfs(0, -1);

    return ans;
  }
};
