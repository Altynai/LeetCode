class Solution {
public:
  int networkBecomesIdle(vector<vector<int>> &e, vector<int> &p) {
    int n = p.size();
    vector<vector<int>> g(n);
    for (auto &edge : e) {
      g[edge[0]].push_back(edge[1]);
      g[edge[1]].push_back(edge[0]);
    }

    vector<int> level(n, -1);
    queue<int> que;
    level[0] = 0;
    que.push(0);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int v : g[u]) {
        if (level[v] == -1) {
          level[v] = level[u] + 1;
          que.push(v);
        }
      }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      int backTime = level[i] * 2;
      // 0, p, 2p, 3p, ... np < backTime
      int num = (backTime - 1) / p[i] + 1;
      int lastSent = (num - 1) * p[i];
      ans = max(ans, lastSent + backTime);
    }
    return ans + 1;
  }
};
