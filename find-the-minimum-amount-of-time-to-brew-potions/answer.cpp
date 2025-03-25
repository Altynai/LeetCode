using int64 = long long;

class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size(), m = mana.size();
    vector<int64> dp(n, 0); // earliest free time
    for (int i = 0; i < m; i++) {
      int64 now = dp[0];
      for (int j = 0; j < n; j++) {
        now = max(dp[j], now) + skill[j] * mana[i];
      }
      for (int j = n - 1; j >= 0; j--) {
        dp[j] = now;
        now -= skill[j] * mana[i];
      }
    }
    return dp[n - 1];
  }
};
