/*
https://oi-wiki.org/string/z-func/

z[i] = LCP(s, s[i, n - 1]), especially: z[0] = 0

z(aaaaa) = [0, 4, 3, 2, 1]
z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
*/
vector<int> z_function(const string &s) {
  int n = (int)s.length();
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
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    string sb = b + "#" + s;
    vector<int> zb = z_function(sb);
    set<int> indices;
    for (int i = b.size() + 1; i < sb.size(); i++) {
      int j = i - (b.size() + 1);
      if (zb[i] >= b.size())
        indices.insert(j);
    }

    vector<int> ans;
    string sa = a + "#" + s;
    vector<int> za = z_function(sa);
    for (int j = a.size() + 1; j < sa.size(); j++) {
      int i = j - (a.size() + 1);
      if (za[j] >= a.size()) {
        // i - k <= j <= i + k
        auto it = indices.lower_bound(i - k);
        if (it != indices.end() and *it <= i + k)
          ans.push_back(i);
      }
    }
    return ans;
  }
};
