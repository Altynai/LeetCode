class Solution {
public:
  int longestSubsequence(string s, int k) {
    int n = s.size();
    int m = 0;
    for (int x = k; x > 0; x /= 2)
      m++;

    if (n < m)
      return n;

    int x = 0;
    for (int i = n - 1; i >= n - m; i--)
      if (s[i] == '1')
        x |= 1 << (n - 1 - i);

    int ans = 0, zero = count(s.begin(), s.begin() + n - m, '0');
    for (int i = n - m; i < n; i++) {
      if (x <= k)
        ans = max(ans, n - i + zero);
      if (s[i] == '1')
        x -= (1 << (n - 1 - i));
      else
        zero++;
    }
    return ans;
  }
};
