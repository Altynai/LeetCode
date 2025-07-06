class Solution {
public:
  int minTime(int n, vector<vector<int>> &edges) {
    using Edge = array<int, 3>;
    vector<vector<Edge>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back({e[1], e[2], e[3]});
    }

    vector<int> tm(n, INT_MAX);
    using State = pair<int, int>; // time, node
    priority_queue<State, vector<State>, greater<State>> q;
    tm[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
      auto [t, u] = q.top();
      q.pop();
      // skip invalid node
      if (tm[u] != t)
        continue;

      for (auto [v, start, end] : adj[u]) {
        if (t > end)
          continue;
        int t2 = (t < start ? start + 1 : t + 1);
        if (t2 < tm[v]) {
          tm[v] = t2;
          q.push({tm[v], v});
        }
      }
    }
    return tm[n - 1] == INT_MAX ? -1 : tm[n - 1];
  }
};
