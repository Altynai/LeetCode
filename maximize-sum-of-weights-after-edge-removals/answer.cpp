template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

using Edge = pair<int, int>; // vertex, weight

template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

// names
class Solution {
public:
  long long maximizeSumOfWeights(vector<vector<int>> &edges, int k) {
    // dp[i][1]: choose the edge between i and fa[i]
    // dp[i][0]: don't choose the edge between i and fa[i]
    // for transition we can select k or k - 1 dp[son][1] to maximize the sum,
    // as we always get dp[son][0], then we can sort by the delta of dp[son][1]
    // - dp[son][0] as gain

    int m = edges.size();
    int n = m + 1;

    vector<vector<Edge>> adj(n);
    for (auto e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<vector<int64>> dp(n, vector<int64>(2, LLONG_MIN));

    // maximal sum of picking at most num times of dp[son][1]
    auto Select = [&](int u, int fa, int num) -> int64 {
      if (adj[u].size() == 1 and u != 0)
        return 0;

      int64 sum = 0;
      min_priority_queue<int64> que;
      for (auto [v, w] : adj[u]) {
        if (v == fa)
          continue;
        sum += dp[v][0];
        int64 gain = dp[v][1] - dp[v][0];
        if (gain >= 0)
          que.push(gain);
        if (que.size() > num)
          que.pop();
      }

      while (!que.empty()) {
        sum += que.top();
        que.pop();
      }
      return sum;
    };

    // w: weight of u <-> fa
    function<void(int, int, int)> dfs = [&](int u, int fa, int weight) {
      if (adj[u].size() == 1) {
        dp[u][0] = 0;
        dp[u][1] = weight;
        return;
      }

      for (auto [v, w] : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u, w);
      }

      umax(dp[u][0], Select(u, fa, k));
      umax(dp[u][1], Select(u, fa, k - 1) + weight);
    };

    for (auto [v, w] : adj[0]) {
      dfs(v, 0, w);
    }

    return Select(0, -1, k);
  }
};
