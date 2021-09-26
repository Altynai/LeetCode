class Solution {
public:
  int scoreOfStudents(string s, vector<int> &answers) {
    const int M = 1000;
    vector<int> cnt(M + 1, 0);
    for (int val : answers)
      cnt[val] += 1;

    int n = s.size();
    vector<vector<set<int>>> dp(n, vector<set<int>>(n));

    function<void(int, int)> dfs = [&](int l, int r) {
      if (!dp[l][r].empty())
        return;
      if (l == r) {
        dp[l][r].insert(s[l] - '0');
        return;
      }

      for (int i = l + 1; i < r; i += 2) {
        dfs(l, i - 1);
        dfs(i + 1, r);
        for (int x : dp[l][i - 1]) {
          for (int y : dp[i + 1][r]) {
            int val = (s[i] == '+' ? x + y : x * y);
            if (val <= M)
              dp[l][r].insert(val);
          }
        }
      }
    };

    vector<int> stk;
    stk.push_back(s[0] - '0');
    for (int i = 1; i < s.size(); i += 2) {
      if (s[i] == '*') {
        stk.back() *= s[i + 1] - '0';
      } else {
        stk.push_back(s[i + 1] - '0');
      }
    }
    int correct = accumulate(stk.begin(), stk.end(), 0);
    dfs(0, n - 1);

    int ans = (correct <= M ? cnt[correct] * 5 : 0);
    for (int val : dp[0][n - 1]) {
      if (val <= M && correct != val)
        ans += cnt[val] * 2;
    }
    return ans;
  }
};
