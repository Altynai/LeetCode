const int N = 26;

class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.size();
    vector<int> dp(N, 0);
    dp[s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
      vector<int> ndp = dp;
      int idx = s[i] - 'a';
      for (int j = max(0, idx - k); j <= min(N - 1, idx + k); j++)
        ndp[idx] = max(ndp[idx], dp[j] + 1);
      dp = ndp;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
