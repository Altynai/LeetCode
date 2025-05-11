template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long subtreeInversionSum(vector<vector<int>> &edges, vector<int> &a,
                                int k) {
    if (k == 1) {
      int64 ans = 0;
      for (int x : a)
        ans += abs(x);
      return ans;
    }

    // f[i][j]: maximal sum of subtree rooted at i and the previous inverted
    // node is j edges away g[i][j]: minimal sum of same definition

    int n = a.size();
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<vector<int64>> f(n, vector<int64>(k + 1, LLONG_MIN));
    vector<vector<int64>> g(n, vector<int64>(k + 1, LLONG_MAX));
    function<void(int, int)> dfs = [&](int u, int fa) {
      // leaf
      if (u != 0 and adj[u].size() == 1) {
        // do nothing
        f[u][k - 1] = g[u][k - 1] = a[u];
        // invert
        f[u][0] = g[u][0] = -a[u];
        return;
      }

      unordered_map<int, int64> maxv, minv;
      for (int v : adj[u]) {
        if (v != fa) {
          dfs(v, u);
          maxv[v] = LLONG_MIN;
          minv[v] = LLONG_MAX;
        }
      }

      // do nothing
      for (int i = k; i >= 1; i--) {
        // f[u][i] can be derived from f[v][i - 1], f[v][i], f[v][i + 1], ....
        for (int v : adj[u]) {
          if (v == fa)
            continue;
          umax(maxv[v], f[v][i - 1]);
          umin(minv[v], g[v][i - 1]);
        }

        int64 maxs = 0, mins = 0;
        for (int v : adj[u]) {
          if (v == fa)
            continue;
          maxs += maxv[v];
          mins += minv[v];
        }
        umax(f[u][i], maxs + a[u]);
        umin(g[u][i], mins + a[u]);
      }

      // invert node u
      int64 maxs = 0, mins = 0;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        maxs += f[v][k - 1];
        mins += g[v][k - 1];
      }
      umax(f[u][0], -mins - a[u]);
      umin(g[u][0], -maxs - a[u]);
    };
    dfs(0, -1);
    return *max_element(f[0].begin(), f[0].end());
  }
};
