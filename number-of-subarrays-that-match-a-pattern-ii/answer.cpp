/*
https://oi-wiki.org/string/z-func/

z[i] = LCP(s, s[i, n - 1]), especially: z[0] = 0

z(aaaaa) = [0, 4, 3, 2, 1]
z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
*/
vector<int> z_function(const vector<int> &s) {
  int n = (int)s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
    }
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

class Solution {
public:
  int countMatchingSubarrays(vector<int> &a, vector<int> &pattern) {
    int n = a.size(), m = pattern.size();

    vector<int> s = pattern;
    s.push_back(2); // splitter
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] == a[i + 1])
        s.push_back(0);
      else if (a[i] < a[i + 1])
        s.push_back(1);
      else
        s.push_back(-1);
    }

    vector<int> z = z_function(s);
    int ans = 0;
    for (int i = m + 1; i < z.size(); i++) {
      if (z[i] == m)
        ans++;
    }
    return ans;
  }
};
