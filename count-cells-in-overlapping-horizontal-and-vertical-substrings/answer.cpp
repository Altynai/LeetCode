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
public:
  int countCells(vector<vector<char>> &a, string pattern) {
    int n = a.size(), m = a[0].size();
    int k = pattern.size();

    string s(n * m, '#');
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        s[i * m + j] = a[i][j];
    }
    string t = pattern + "@" + s;
    vector<int> z = z_function(t);

    auto Mark = [&](vector<int> &v, int l, int r) {
      int sz = v.size();
      v[l]++;
      if (r + 1 < sz)
        v[r + 1]--;
    };

    auto Merge = [&](vector<int> &v) {
      int sz = v.size();
      for (int i = 1; i < sz; i++)
        v[i] += v[i - 1];
    };

    // horizontal
    vector<int> good(n * m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int id = i * m + j;
        if (z[k + 1 + id] == k)
          Mark(good, id, id + k - 1);
      }
    }
    Merge(good);

    // vertical
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        int id2 = j * n + i;
        s[id2] = a[i][j];
      }
    }
    t = pattern + "@" + s;
    vector<int> z2 = z_function(t);

    vector<int> good2(n * m, 0);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        int id2 = j * n + i;
        if (z2[k + 1 + id2] == k)
          Mark(good2, id2, id2 + k - 1);
      }
    }
    Merge(good2);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int id = i * m + j;
        int id2 = j * n + i;
        if (good[id] and good2[id2])
          ans++;
      }
    }
    return ans;
  }
};
