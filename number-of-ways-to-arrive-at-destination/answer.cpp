class Solution {
public:
  int countPaths(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> g(n);
    for (auto &road : roads) {
      g[road[0]].emplace_back(road[1], road[2]);
      g[road[1]].emplace_back(road[0], road[2]);
    }

    const int MOD = 1e9 + 7;
    vector<long long> dis(n, LLONG_MAX);
    vector<int> ways(n, 0);

    using State = pair<long long, int>;
    priority_queue<State, vector<State>, greater<State>> q;

    dis[0] = 0, ways[0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      for (auto [v, w] : g[u]) {
        if (d + w == dis[v]) {
          ways[v] = (ways[v] + ways[u]) % MOD;
          dis[v] = d + w;
        } else if (d + w < dis[v]) {
          ways[v] = ways[u];
          dis[v] = d + w;
          q.push({dis[v], v});
        }
      }
    }
    return ways[n - 1];
  }
};
