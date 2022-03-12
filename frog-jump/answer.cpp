class Solution {
public:
  bool canCross(vector<int> &s) {
    int n = s.size();
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
      pos[s[i]] = i;

    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
      for (int k = 0; k < n; k++)
        if (dp[i][k]) {
          for (int delta = -1; delta <= 1; delta++) {
            int where = s[i] + k + delta;
            if (where <= s[i] or pos.count(where) == 0)
              continue;

            int j = pos[where];
            dp[j][k + delta] = 1;
          }
        }
    }

    for (int k = 0; k < n; k++)
      if (dp[n - 1][k])
        return true;
    return false;
  }
};
