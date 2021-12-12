class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int> &a, int time) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] <= a[i + 1])
        dp[i] = dp[i + 1] + 1;
      else
        dp[i] = 1;
    }

    vector<int> ans;
    int len = 1;
    for (int i = 0; i < n; i++) {
      if (i && a[i - 1] >= a[i])
        len += 1;
      else
        len = 1;

      if (len - 1 >= time && dp[i] - 1 >= time)
        ans.push_back(i);
    }
    return ans;
  }
};
