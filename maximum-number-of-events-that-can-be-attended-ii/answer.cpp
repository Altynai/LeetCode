class Solution {
public:
  int maxValue(vector<vector<int>> &events, int k) {
    int n = events.size();
    sort(events.begin(), events.end());
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    function<int(int, int)> dfs = [&](int i, int j) -> int {
      // dp[i][j]: maximum score when picks j from [1 ... i]
      if (i == n || j == 0)
        return 0;
      if (dp[i][j] != -1)
        return dp[i][j];

      int p = i + 1;
      for (; p < n && events[p][0] <= events[i][1]; p++)
        ;
      return dp[i][j] = max(events[i][2] + dfs(p, j - 1), dfs(i + 1, j));
    };

    return dfs(0, k);
  }
};
