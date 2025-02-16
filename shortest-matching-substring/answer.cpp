/*
https://oi-wiki.org/string/z-func/

z[i] = LCP(s, s[i, n - 1]), especially: z[0] = 0

z(aaaaa) = [0, 4, 3, 2, 1]
z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
*/
vector<int> z_function(const string &s) {
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

  set<int> findPositions(const string &s, const string &p) {
    int m = p.size();
    string t = p + "#" + s;
    vector<int> z = z_function(t);

    set<int> ans;
    for (int i = m + 1; i < t.size(); i++) {
      if (z[i] == m)
        ans.insert(i - m - 1);
    }
    return ans;
  };

  int handleOne(const string &s, const string &p) {
    set<int> res = findPositions(s, p);
    return res.empty() ? -1 : p.size();
  }

  int handleTwo(const string &s, const string &p, const string &q) {
    set<int> fi = findPositions(s, p);
    set<int> se = findPositions(s, q);

    int ans = INT_MAX;
    for (int pos : fi) {
      auto it = se.lower_bound(pos + p.size());
      if (it != se.end())
        ans = min(ans, *it + (int)q.size() - pos);
    }
    return ans == INT_MAX ? -1 : ans;
  }

  int handleThree(const string &s, const string &p, const string &q,
                  const string &r) {
    set<int> fi = findPositions(s, p);
    set<int> se = findPositions(s, q);
    set<int> th = findPositions(s, r);

    int ans = INT_MAX;
    for (int pos : se) {
      int ll = -1, rr = -1;
      auto it = fi.lower_bound(pos - p.size() + 1);
      if (it == fi.begin())
        continue;
      ll = *prev(it);
      it = th.lower_bound(pos + q.size());
      if (it == th.end())
        continue;
      rr = *it + (int)r.size() - 1;

      ans = min(ans, rr - ll + 1);
    }
    return ans == INT_MAX ? -1 : ans;
  }

public:
  int shortestMatchingSubstring(string s, string p) {
    int m = p.size();
    vector<int> where;
    for (int i = 0; i < m; i++) {
      if (p[i] == '*')
        where.push_back(i);
    }

    int x = where[0], y = where[1];
    // cases of 1 string
    if (x == 0 and y == m - 1)
      return m == 2 ? 0 : handleOne(s, p.substr(1, m - 2));
    else if (x == 0 and y == 1)
      return handleOne(s, p.substr(2));
    else if (x == m - 2 and y == m - 1)
      return handleOne(s, p.substr(0, m - 2));

    // cases of 2 strings
    else if (x + 1 == y)
      return handleTwo(s, p.substr(0, x), p.substr(y + 1));
    else if (x == 0 and y < m - 1)
      return handleTwo(s, p.substr(1, y - 1), p.substr(y + 1));
    else if (x > 0 and y == m - 1)
      return handleTwo(s, p.substr(0, x), p.substr(x + 1, y - x - 1));

    // cases of 3 strings
    else
      return handleThree(s, p.substr(0, x), p.substr(x + 1, y - x - 1),
                         p.substr(y + 1));
  }
};
