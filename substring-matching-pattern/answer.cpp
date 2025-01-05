class Solution {
public:
  bool hasMatch(string s, string p) {
    int n = s.size(), m = p.size();
    int pos = p.find('*');

    for (int i = 0; i < n; i++) {
      for (int j = i + m - 2; j < n; j++) {
        int len = j - i + 1;
        string t = s.substr(i, len);
        if (pos == 0) {
          if (t.substr(len - (m - 1)) == p.substr(1))
            return 1;
        } else if (pos == m - 1) {
          if (t.substr(0, m - 1) == p.substr(0, m - 1))
            return 1;
        } else {
          string pfx = p.substr(0, pos);
          string sfx = p.substr(pos + 1);
          if (t.substr(0, pfx.size()) == pfx and
              t.substr(len - sfx.size()) == sfx)
            return 1;
        }
      }
    }
    return 0;
  }
};
