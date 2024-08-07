template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  vector<int> timeTaken(vector<vector<int>> &es) {
    int n = es.size() + 1;

    vector<vector<int>> adj(n, vector<int>());
    for (auto &e : es) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> dis(n, 0);
    function<int(int, int)> dfs = [&](int u, int fa) -> int {
      dis[u] = 0;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        int w = (v % 2 == 0) ? 2 : 1; // u -> v
        umax(dis[u], dfs(v, u) + w);
      }
      return dis[u];
    };
    dfs(0, -1);

    function<void(int, int, int)> dfs2 = [&](int u, int fa, int prev_best) {
      int w = 0;
      if (fa != -1)
        w = (fa % 2 == 0) ? 2 : 1;
      int val = prev_best + w;
      umax(dis[u], val);

      int largest = 0, second = 0;
      for (int v : adj[u]) {
        if (v == fa)
          continue;

        int w = (v % 2 == 0) ? 2 : 1; // u -> v
        int res = dis[v] + w;
        if (res >= largest)
          second = largest, largest = res;
        else if (res > second)
          second = res;
      }

      for (int v : adj[u]) {
        if (v == fa)
          continue;
        int w = (v % 2 == 0) ? 2 : 1; // u -> v
        int res = dis[v] + w;
        int other = (res == largest ? second : largest);
        dfs2(v, u, max(other, val));
      }
    };
    dfs2(0, -1, 0);

    return dis;
  }
};
