class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    vector<int> deg(n, 0);
    for (auto &edge : edges) {
      int u = edge[0] - 1;
      int v = edge[1] - 1;
      if (++deg[u] == n - 1)
        return u + 1;
      if (++deg[v] == n - 1)
        return v + 1;
    }
    return -1;
  }
};
