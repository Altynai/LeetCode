class Solution {
public:
  int minIncrements(int n, vector<int> &cost) {
    int maxVal = 0;
    function<void(int, int)> dfs = [&](int u, int val) {
      val += cost[u - 1];
      if ((u << 1) > n)
        maxVal = max(val, maxVal);
      else {
        dfs(u << 1, val);
        dfs(u << 1 | 1, val);
      }
    };
    dfs(1, 0);

    int ans = 0;
    function<int(int, int)> dfs2 = [&](int u, int val) -> int {
      val += cost[u - 1];
      if ((u << 1) > n) {
        return maxVal - val;
      } else {
        int x = dfs2(u << 1, val);
        int y = dfs2(u << 1 | 1, val);
        int z = min(x, y);
        ans += x + y - z * 2;
        return z;
      }
    };
    ans += dfs2(1, 0);
    return ans;
  }
};
