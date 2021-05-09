// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();
    vector<int> deg(n, 0);
    vector<vector<int>> e(n, vector<int>());
    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      deg[v]++;
      e[u].push_back(v);
    }

    vector<int> vis(n, 0);
    vector<vector<int>> dp(n, vector<int>(26, 0));
    bool foundCycle = 0;

    function<void(int)> dfs = [&](int u) -> void {
      vis[u] = 1;
      for (int v : e[u]) {
        if (vis[v] == 1)
          foundCycle = 1;
        if (foundCycle)
          return;

        if (vis[v] == 0)
          dfs(v);
        for (int i = 0; i < 26; i++)
          umax(dp[u][i], dp[v][i]);
      }
      dp[u][colors[u] - 'a']++;
      vis[u] = 2;
    };

    for (int i = 0; i < n; i++) {
      if (vis[i] == 0)
        dfs(i);
      if (foundCycle)
        return -1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, *max_element(dp[i].begin(), dp[i].end()));
    }
    return ans;
  }
};
