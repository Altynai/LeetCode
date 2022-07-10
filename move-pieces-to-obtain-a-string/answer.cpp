class Solution {
public:
  bool canChange(string s, string t) {
    int n = s.size();
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      if (s[i] != '_')
        a.push_back(i);
      if (t[i] != '_')
        b.push_back(i);
    }
    if (a.size() != b.size())
      return false;

    int m = a.size();
    for (int i = 0; i < m; i++) {
      if (s[a[i]] != t[b[i]])
        return false;
    }

    for (int i = 0; i < m;) {
      int j = i;
      while (j < m and s[a[j]] == s[a[i]])
        j++;

      if (s[a[i]] == 'L') {
        for (int k = i; k < j; k++) {
          if (a[k] < b[k])
            return false;
        }
      } else {
        for (int k = i; k < j; k++) {
          if (a[k] > b[k])
            return false;
        }
      }

      i = j;
    }
    return true;
  }
};
