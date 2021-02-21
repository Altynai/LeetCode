class Solution {
public:
  vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
    int n = nums.size();
    vector<vector<int>> g(n);
    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> dep(n, 0);
    function<void(int, int, int)> dfs = [&](int u, int pa, int d) {
      dep[u] = d;
      for (int v : g[u]) {
        if (v == pa)
          continue;
        dfs(v, u, d + 1);
      }
    };
    dfs(0, -1, 0);

    vector<int> ans(n, -1);
    deque<int> seen[51];

    function<void(int, int)> dfs2 = [&](int u, int pa) {
      for (int i = 1; i <= 50; i++) {
        if (seen[i].empty())
          continue;
        int v = seen[i].back();
        if (gcd(i, nums[u]) == 1) {
          if (ans[u] == -1 || dep[v] > dep[ans[u]])
            ans[u] = v;
        }
      }

      seen[nums[u]].push_back(u);
      for (int v : g[u]) {
        if (v == pa)
          continue;
        dfs2(v, u);
      }
      seen[nums[u]].pop_back();
    };

    dfs2(0, -1);
    return ans;
  }
};
