class Solution {
public:
  int cal(const vector<int> &a, int k) {
    int n = a.size();
    if (n == 0)
      return 1;

    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      vector<int> ndp = dp;
      for (int j = 0; j < i; j++) {
        if (a[i] - k != a[j])
          ndp[i] += dp[j];
      }
      ndp[i]++;
      dp = ndp;
    }
    return accumulate(dp.begin(), dp.end(), 0) + 1;
  }

  int beautifulSubsets(vector<int> &a, int k) {
    sort(a.begin(), a.end());

    vector<vector<int>> groups(k);
    for (int x : a)
      groups[x % k].push_back(x);

    int ans = 1;
    for (int i = 0; i < k; i++)
      ans *= cal(groups[i], k);
    return ans - 1;
  }
};
