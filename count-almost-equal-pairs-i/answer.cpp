class Solution {
private:
  bool equal(const string &s, const string &t) {
    if (s == t)
      return 1;
    int n = s.size(), m = t.size();
    vector<pair<int, int>> pos;
    for (int i = n - 1, j = m - 1; i >= 0 or j >= 0; i--, j--) {
      int x = (i >= 0 ? s[i] - '0' : 0);
      int y = (j >= 0 ? t[j] - '0' : 0);
      if (x != y)
        pos.push_back({x, y});
    }
    return pos.size() == 2 and pos[0].first == pos[1].second and
           pos[1].first == pos[0].second;
  }

public:
  int countPairs(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      string s = to_string(a[i]);
      for (int j = 0; j < i; j++) {
        string t = to_string(a[j]);
        if (equal(s, t))
          ans++;
      }
    }
    return ans;
  }
};
