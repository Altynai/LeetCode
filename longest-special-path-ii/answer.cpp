class Solution {
public:
  vector<int> longestSpecialPath(vector<vector<int>> &edges,
                                 vector<int> &nums) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    for (auto e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    int ans = 0, nodes = INT_MAX;
    auto Update = [&](int len, int cnt) {
      if (len > ans or (len == ans and cnt < nodes))
        ans = len, nodes = cnt;
    };

    int m = *max_element(nums.begin(), nums.end());
    vector<int> path, psum, cnt(m + 1, 0), last(m + 1, -1);

    function<void(int, int, int, int, int, int)> dfs =
        [&](int u, int fa, int weight, int top, int down, int twice) {
          int prev_level = last[nums[u]];

          last[nums[u]] = down;
          path.push_back(u);
          psum.push_back((psum.empty() ? 0 : psum.back()) + weight);

          while (top <= min(prev_level, twice))
            top++;
          if (prev_level != -1)
            twice = max(twice, prev_level);

          Update(psum.back() - psum[top], down - top + 1);

          for (auto [v, w] : adj[u]) {
            if (v == fa)
              continue;
            dfs(v, u, w, top, down + 1, twice);
          }

          // reverse
          path.pop_back();
          psum.pop_back();
          last[nums[u]] = prev_level;
        };
    dfs(0, -1, 0, 0, 0, -1);

    vector<int> res = {ans, nodes};
    return res;
  }
};
