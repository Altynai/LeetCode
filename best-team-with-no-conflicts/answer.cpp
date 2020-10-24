class Solution {
public:
  int bestTeamScore(vector<int> &s, vector<int> &a) {
    int n = s.size();

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
      p.emplace_back(a[i], s[i]);
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    int ans = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
      dp[i] = p[i].second;
      for (int j = 0; j < i; j++) {
        if (p[j].first == p[i].first || p[j].second >= p[i].second) {
          dp[i] = max(dp[i], dp[j] + p[i].second);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
