class Solution {
public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    vector<unordered_set<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].insert(e[1]);
      adj[e[1]].insert(e[0]);
    }

    int remain = n;

    // remove leaf nodes without coin
    for (int i = 0; i < n; i++) {
      int u = i;
      while (coins[u] == 0 and adj[u].size() == 1) {
        int v = *adj[u].begin();
        adj[u].clear();
        adj[v].erase(u);

        remain--;
        u = v;
      }
    }

    // remove leaf with coins
    queue<int> q;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++) {
      if (coins[i] == 1 and adj[i].size() == 1) {
        vis[i] = 1;
        remain--;
        q.push(i);
      }
    }

    // remove their parents
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : adj[u]) {
        if (vis[v])
          continue;
        adj[v].erase(u);
        if (!vis[v] and adj[v].size() <= 1) {
          vis[v] = 1;
          remain--;
        }
      }
      adj[u].clear();
    }
    return max(0, remain - 1) * 2;
  }
};
