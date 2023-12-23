using int64 = long long;
using State = pair<vector<int>, vector<int>>;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost) {
    int n = cost.size();

    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<int64> ans(n, 0);
    vector<int> sz(n, 0);

    function<State(int, int)> dfs = [&](int u, int fa) -> State {
      vector<int> pos, neg;
      if (cost[u] > 0)
        pos.push_back(cost[u]);
      else if (cost[u] < 0)
        neg.push_back(cost[u]);

      sz[u] = 1;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        auto [_pos, _neg] = dfs(v, u);
        sz[u] += sz[v];
        pos.insert(pos.end(), _pos.begin(), _pos.end());
        neg.insert(neg.end(), _neg.begin(), _neg.end());
      }

      sort(pos.begin(), pos.end());
      sort(neg.begin(), neg.end());

      if (pos.size() >= 3)
        pos = vector<int>(pos.end() - 3, pos.end());
      if (neg.size() >= 3)
        neg = vector<int>(neg.begin(), neg.begin() + 3);

      if (sz[u] < 3)
        ans[u] = 1;
      else {
        int npos = pos.size(), nneg = neg.size();
        if (npos >= 3)
          umax(ans[u], 1LL * pos[npos - 1] * pos[npos - 2] * pos[npos - 3]);
        if (npos >= 1 and nneg >= 2)
          umax(ans[u], 1LL * pos[npos - 1] * neg[0] * neg[1]);
      }

      return {pos, neg};
    };
    dfs(0, -1);

    return ans;
  }
};
