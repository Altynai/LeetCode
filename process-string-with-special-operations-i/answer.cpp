class Solution {
public:
  string processStr(string s) {
    int n = s.size();
    string t;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        if (t.size() > 0)
          t.pop_back();
      } else if (s[i] == '#')
        t += t;
      else if (s[i] == '%')
        reverse(t.begin(), t.end());
      else
        t.push_back(s[i]);
    }
    return t;
  }
};
