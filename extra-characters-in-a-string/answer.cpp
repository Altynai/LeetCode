class Solution {
public:
  int minExtraChar(string s, vector<string> &dict) {
    unordered_set<string> d(dict.begin(), dict.end());
    int n = s.size();
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j >= 1; j--) {
        int len = i - j + 1;
        string t = s.substr(j - 1, len);
        if (d.find(t) != d.end())
          dp[i] = min(dp[i], dp[j - 1]);
        else
          dp[i] = min(dp[i], dp[j - 1] + len);
      }
    }
    return dp[n];
  }
};
