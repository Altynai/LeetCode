class Solution {
public:
  string maxValue(string s, int x) {
    int n = s.size(), pos = -1;
    if (s[0] == '-') {
      for (int i = 1; i < n; i++) {
        if (x < s[i] - '0') {
          pos = i;
          break;
        }
      }
      if (pos == -1) {
        for (int i = n - 1; i >= 1; i--) {
          if (x > s[i] - '0') {
            pos = i + 1;
            break;
          }
        }
      }
      if (pos == -1)
        pos = 1;
    } else {
      pos = n;
      for (int i = 0; i < n; i++) {
        if (x > s[i] - '0') {
          pos = i;
          break;
        }
      }
    }
    if (pos == n)
      s.push_back('0' + x);
    else
      s.insert(s.begin() + pos, (char)('0' + x));
    return s;
  }
};
