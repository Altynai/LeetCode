class Solution {
public:
  int maximumTastiness(vector<int> &a, int k) {
    sort(a.begin(), a.end());

    int n = a.size(), ans = -1;
    vector<int> dp(n);
    for (int l = 0, r = a[n - 1]; l <= r;) {
      int mid = (l + r) / 2;
      dp[0] = 1;
      for (int i = 1, j = 0; i < n; i++) {
        while (j + 1 <= i and a[j + 1] + mid <= a[i])
          j++;
        dp[i] = max(dp[i - 1], 1);
        if (a[j] + mid <= a[i])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[n - 1] >= k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
