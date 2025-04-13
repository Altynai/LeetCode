template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

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
  int longestPalindrome(string s, string t) {
    int n = s.size(), m = t.size();

    vector<int> p(n, 1);
    Manacher manacher(s);
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j > i; j--) {
        if (manacher.isPalindrome(i, j)) {
          p[i] = j - i + 1;
          break;
        }
      }
    }

    vector<int> q(m, 1);
    manacher = Manacher(t);
    for (int j = m - 1; j >= 0; j--) {
      for (int i = 0; i < j; i++) {
        if (manacher.isPalindrome(i, j)) {
          q[j] = j - i + 1;
          break;
        }
      }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    auto Get = [&](int i, int j) -> int {
      if (0 <= i and i < n)
        return (0 <= j and j < m) ? dp[i][j] : p[i];
      return (0 <= j and j < m) ? q[j] : 0;
    };

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        umax(dp[i][j], max(p[i], q[j]));
        if (s[i] == t[j])
          umax(dp[i][j], 2 + Get(i + 1, j - 1));
        umax(ans, dp[i][j]);
      }
    }
    return ans;
  }
};
