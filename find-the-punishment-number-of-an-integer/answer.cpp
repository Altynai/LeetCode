class Solution {
private:
  bool valid(int x, int k) {
    string s = to_string(x);
    int n = s.size();
    vector<unordered_set<int>> dp(n + 1);
    dp[0].insert(0);

    for (int i = 1; i <= n; i++) {
      int val = 0, ten = 1;
      for (int j = i; j >= 1; j--) {
        val += ten * (s[j - 1] - '0');
        ten *= 10;
        for (int y : dp[j - 1]) {
          if (y + val <= k)
            dp[i].insert(y + val);
        }
      }
    }
    return dp[n].count(k);
  }

public:
  int punishmentNumber(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (valid(i * i, i))
        ans += i * i;
    }
    return ans;
  }
};
