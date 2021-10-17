class Solution {
public:
  int secondMinimum(int n, vector<vector<int>> &e, int time, int change) {
    vector<vector<int>> g(n);
    for (auto &edge : e) {
      g[edge[0] - 1].push_back(edge[1] - 1);
      g[edge[1] - 1].push_back(edge[0] - 1);
    }

    vector<int> best(n, INT_MAX), second(n, INT_MAX);
    auto update = [&](int u, int d) -> bool {
      if (best[u] == INT_MAX) {
        best[u] = d;
        return 1;
      } else if (d < best[u]) {
        second[u] = best[u];
        best[u] = d;
        return 1;
      } else if (d > best[u] && (second[u] == INT_MAX || d < second[u])) {
        second[u] = d;
        return 1;
      }
      return 0;
    };

    auto wait = [&](int d) -> int {
      // green ranges: [0,c) [2c, 3), 4c, ...
      int p = d / change;
      if (p % 2 == 0)
        return d;
      return (p + 1) * change;
    };

    queue<int> que;
    vector<bool> inq(n, 0);
    best[0] = 0;
    inq[0] = 1;
    que.push(0);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      inq[u] = 0;
      for (int i = 0; i < 2; i++) {
        int d = (i == 0 ? best[u] : second[u]);
        if (d == INT_MAX)
          continue;

        d = wait(d);
        for (int v : g[u]) {
          if (update(v, d + time) && !inq[v]) {
            que.push(v);
            inq[v] = 1;
          }
        }
      }
    }

    if (second[n - 1] != INT_MAX)
      return second[n - 1];

    for (int v : g[n - 1]) {
      for (int i = 0; i < 2; i++) {
        int d = (i == 0 ? best[n - 1] : second[n - 1]);
        if (d == INT_MAX)
          continue;

        d = wait(d);
        // go back to a node
        d += time;
        d = wait(d);
        update(n - 1, d + time);
      }
    }
    return second[n - 1];
  }
};
