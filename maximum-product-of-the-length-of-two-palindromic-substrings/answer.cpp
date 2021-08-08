/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded
 * down). Time: O(N) Status: Stress-tested
 */
array<vector<int>, 2> manacher(const string &s) {
  int n = s.size();
  array<vector<int>, 2> p = {vector<int>(n + 1), vector<int>(n)};
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
  return p;
}

class Solution {
public:
  long long maxProduct(string s) {
    auto [_, odd] = manacher(s);

    int n = s.size();
    vector<int> a(n, 1), b(n, 1);
    // forward
    for (int i = 0, j = 0; i < n; i++) {
      if (i > 0)
        a[i] = max(a[i], a[i - 1]);
      while (j < i && j + odd[j] < i)
        j++;
      if (j < i)
        a[i] = max(a[i], (i - j) * 2 + 1);
    }

    // backward
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
      if (i < n - 1)
        b[i] = max(b[i], b[i + 1]);
      while (j > i && j - odd[j] > i)
        j--;
      if (j > i)
        b[i] = max(b[i], (j - i) * 2 + 1);
    }

    long long ans = 0;
    for (int i = 0; i + 1 < n; i++)
      ans = max(ans, 1LL * a[i] * b[i + 1]);
    return ans;
  }
};
