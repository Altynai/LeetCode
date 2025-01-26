template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

class Solution {
public:
  vector<int> longestSpecialPath(vector<vector<int>> &edges,
                                 vector<int> &nums) {
    int n = nums.size();
    vector<vector<pair<int, int>>> adj(n);
    for (auto e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<int> v = nums;
    int m = deduplicate(v);
    for (int &x : nums)
      x = lower_bound(v.begin(), v.end(), x) - v.begin();

    vector<int> depth(n);
    set<int> last_seen;
    vector<vector<int>> stack(m);
    vector<int> psum(n, 0);

    int length = 0, nodes = 1;
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
      depth[u] = d;

      int val = nums[u];
      stack[val].push_back(u);
      int k = stack[val].size();
      // for nodes with same value (e.g. p -> q -> ... -> u)
      // we should only consider path starting at least depth[p] + 1
      if (k >= 2)
        last_seen.insert(depth[stack[val][k - 2]]);

      int depth_q = 0;
      if (!last_seen.empty())
        depth_q = 1 + *prev(last_seen.end());

      // update answer
      int len = psum[d] - psum[depth_q];
      int cnt = d - depth_q + 1;
      if (len > length or (len == length and cnt < nodes))
        length = len, nodes = cnt;

      for (auto [v, w] : adj[u]) {
        if (v == fa)
          continue;
        psum[d + 1] = psum[d] + w;
        dfs(v, u, d + 1);
      }

      stack[val].pop_back();
      if (k >= 2)
        last_seen.erase(depth[stack[val][k - 2]]);
    };
    dfs(0, -1, 0);
    return {length, nodes};
  }
};
