class Solution {
public:
  int maximumScore(vector<int> &s, vector<vector<int>> &edges) {
    int n = s.size();
    vector<vector<int>> g(n);

    for (auto &e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    auto cmp = [&](int x, int y) -> bool { return s[x] > s[y]; };

    for (int i = 0; i < n; i++)
      sort(g[i].begin(), g[i].end(), cmp);

    int ans = -1;
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      vector<int> su;
      for (int i = 0; i < g[u].size() and su.size() < 2; i++) {
        if (g[u][i] != v)
          su.push_back(g[u][i]);
      }
      vector<int> sv;
      for (int i = 0; i < g[v].size() and sv.size() < 2; i++) {
        if (g[v][i] != u)
          sv.push_back(g[v][i]);
      }

      for (int x : su) {
        for (int y : sv) {
          if (x != y)
            ans = max(ans, s[u] + s[v] + s[x] + s[y]);
        }
      }
    }
    return ans;
  }
};
