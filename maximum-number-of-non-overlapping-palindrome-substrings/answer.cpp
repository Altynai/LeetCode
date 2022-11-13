/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded
 * down). Time: O(N) Status: Stress-tested
 *
 * p[0][i] = j means s[i - j .. i .. i + j - 1] is a palindrome and s[i] = s[i -
 * 1] p[1][i] = j means s[i - j .. i .. i + j] is a palindrome
 */
struct Manacher {
  int n;
  array<vector<int>, 2> p;

  Manacher(const string &s) {
    n = s.size();
    p = {vector<int>(n + 1), vector<int>(n)};

    for (int z = 0; z < 2; z++) {
      for (int i = 0, l = 0, r = 0; i < n; i++) {
        int t = r - i + !z;
        if (i < r)
          p[z][i] = min(t, p[z][l + t]);
        int L = i - p[z][i], R = i + p[z][i] - !z;
        while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
          p[z][i]++, L--, R++;
        if (R > r)
          l = L, r = R;
      }
    }
  }

  bool isPalindrome(int l, int r) {
    int len = (r - l + 1);
    int middle = l + len / 2;
    if (len % 2 == 1)
      return middle + p[1][middle] >= r;
    else
      return middle + p[0][middle] - 1 >= r;
  }
};

class Solution {
public:
  int maxPalindromes(string s, int k) {
    int n = s.size();
    Manacher m(s);

    vector<int> dp(n + 1, 0);
    for (int i = k; i <= n; i++) {
      dp[i] = dp[i - 1];
      for (int j = i - k + 1; j >= 1; j--) {
        if (m.isPalindrome(j - 1, i - 1))
          dp[i] = max(dp[i], dp[j - 1] + 1);
      }
    }
    return dp[n];
  }
};
