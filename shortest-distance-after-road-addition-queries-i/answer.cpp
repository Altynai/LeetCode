template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n,
                                           vector<vector<int>> &queries) {
    int m = queries.size();

    vector<int> ans(m, 0);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
      int u = queries[i][0], v = queries[i][1];
      adj[u].push_back(v);

      vector<int> dis(n);
      iota(dis.begin(), dis.end(), 0);
      for (int j = 0; j < n - 1; j++) {
        umin(dis[j + 1], dis[j] + 1);
        for (int k : adj[j])
          umin(dis[k], dis[j] + 1);
      }
      ans[i] = dis[n - 1];
    }
    return ans;
  }
};
