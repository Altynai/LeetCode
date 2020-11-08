class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n == 0)
      return 0;

    vector<int> ans(n + 1, 0);
    ans[1] = 1;
    for (int i = 1; i <= n; i++) {
      if (i * 2 <= n)
        ans[i * 2] = ans[i];
      if (i * 2 + 1 <= n)
        ans[i * 2 + 1] = ans[i] + ans[i + 1];
    }
    return *max_element(ans.begin(), ans.end());
  }
};
