class Solution {
public:
  int componentValue(vector<int> &a, vector<vector<int>> &edges) {
    int n = a.size();
    int sum = 0, maxv = *max_element(a.begin(), a.end());
    for (int x : a)
      sum += x;

    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int ans = 0, each = 0, cnt = 0;
    function<int(int, int)> dfs = [&](int u, int fa) -> int {
      int total = a[u];
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        int got = dfs(v, u);
        if (got == -1)
          return -1;

        if (got > 0)
          total += got;
        // got = 0 means sub-tree rooted with v is valid
        // we need to cut edge u <-> v
        else
          cnt++;
      }
      if (total > each)
        return -1;
      else if (total == each)
        return 0;
      else
        return total;
    };

    for (int comp = n; comp >= 2; comp--) {
      if (sum % comp != 0)
        continue;
      each = sum / comp;
      if (each < maxv)
        continue;

      cnt = 0;
      int got = dfs(0, -1);
      if (got == -1)
        continue;
      if (cnt == comp - 1)
        return comp - 1;
    }
    return 0;
  }
};
