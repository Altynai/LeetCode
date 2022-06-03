class Solution {
public:
  int totalSteps(vector<int> &a) {
    int n = a.size();
    stack<int> s;
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() and a[i] > a[s.top()]) {
        dp[i] = max(dp[i] + 1, dp[s.top()]);
        s.pop();
      }
      s.push(i);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
