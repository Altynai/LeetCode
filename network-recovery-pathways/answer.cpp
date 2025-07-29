using int64 = long long;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
                       long long k) {
    int n = online.size();
    vector<vector<pair<int, int>>> adj(n);
    for (auto e : edges)
      adj[e[0]].push_back({e[1], e[2]});

    vector<int64> dis(n);
    auto Test = [&](int val) -> bool {
      dis.assign(n, LLONG_MAX);
      using State = pair<int64, int>;
      priority_queue<State, vector<State>, greater<State>> q;
      dis[0] = 0;
      q.push({0, 0});

      while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        // skip invalid node
        if (dis[u] != d)
          continue;

        for (auto [v, weight] : adj[u]) {
          if (!online[v])
            continue;
          if (weight < val)
            continue;
          int64 w = dis[u] + weight;
          if (w < dis[v]) {
            dis[v] = w;
            q.push({dis[v], v});
          }
        }
      }
      return dis[n - 1] <= k;
    };

    int l = 0, r = 0, ans = -1;
    for (auto e : edges)
      umax(r, e[2]);
    while (l <= r) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
