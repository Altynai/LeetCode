#define maxn 501

class Solution {
public:
  int checkWays(vector<vector<int>> &pairs) {
    vector<vector<int>> g(maxn, vector<int>());
    bool ok[maxn][maxn];
    memset(ok, 0, sizeof(ok));
    for (auto v : pairs) {
      g[v[0]].push_back(v[1]);
      g[v[1]].push_back(v[0]);
      ok[v[0]][v[1]] = ok[v[1]][v[0]] = 1;
    }

    priority_queue<pair<int, int>> pq;
    for (int u = 1; u < maxn; u++) {
      if (g[u].size())
        pq.push({g[u].size(), u});
    }

    int n = pq.size(), ans = 1;
    bool seen[maxn];
    memset(seen, 0, sizeof(seen));
    while (pq.size()) {
      auto [sz, v] = pq.top();
      pq.pop();

      int p = -1;
      int psz = INT_MAX;
      // find the visited and smallest sized node as root
      for (int x : g[v]) {
        if (seen[x] && g[x].size() < psz) {
          p = x;
          psz = g[x].size();
        }
      }
      seen[v] = 1;
      // first root
      if (p == -1) {
        if (sz != n - 1)
          return 0;
        continue;
      }

      if (psz == sz)
        ans = 2;

      for (int x : g[v]) {
        if (x != p && ok[p][x] == 0)
          return 0;
      }
    }
    return ans;
  }
};
