class Solution {
public:
  int countHighestScoreNodes(vector<int> &p) {
    int n = p.size();
    long long score = 0;
    int cnt = 0;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++)
      g[p[i]].push_back(i);

    function<int(int)> dfs = [&](int u) -> int {
      int ans = 1;
      long long s = 1;
      for (int v : g[u]) {
        int c = dfs(v);
        s *= c;
        ans += c;
      }
      s *= max(1, n - ans);
      if (s > score)
        score = s, cnt = 1;
      else if (s == score)
        cnt++;
      return ans;
    };

    dfs(0);
    return cnt;
  }
};
