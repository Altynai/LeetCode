class Solution {
public:
  vector<long long> kthPalindrome(vector<int> &q, int m) {
    long long base = 1;
    for (int j = 0; j < (m + 1) / 2 - 1; j++)
      base *= 10;
    long long cnt = base * 10 - base;

    int n = q.size();
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++) {
      if (q[i] > cnt)
        continue;

      long long val = base + q[i] - 1;
      ans[i] = val;

      if (m & 1)
        val /= 10;
      for (int j = 0; j < m / 2; j++) {
        ans[i] = ans[i] * 10 + val % 10;
        val /= 10;
      }
    }
    return ans;
  }
};
