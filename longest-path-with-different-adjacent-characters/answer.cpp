template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

void shift(int &big, int &small, int val) {
  if (val >= big)
    small = big, big = val;
  else if (val > small)
    small = val;
}

class Solution {
public:
  int longestPath(vector<int> &p, string s) {
    int n = p.size();
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
      g[p[i]].push_back(i);

    int ans = 1;
    function<int(int)> dfs = [&](int u) -> int {
      if (g[u].size() == 0)
        return 1;

      int res = 0, big = 0, small = 0;
      for (int v : g[u]) {
        int len = dfs(v);
        if (s[u] != s[v]) {
          umax(res, len);
          umax(ans, len + 1);
          shift(big, small, len);
        }
      }
      umax(ans, big + small + 1);
      return res + 1;
    };

    dfs(0);
    return ans;
  }
};
