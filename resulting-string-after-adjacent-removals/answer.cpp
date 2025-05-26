class Solution {
  bool good(char x, char y) {
    if (x > y)
      swap(x, y);
    if (x + 1 == y)
      return 1;
    return x == 'a' and y == 'z';
  }

public:
  string resultingString(string s) {
    int n = s.size(), m = 0;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
      v[m++] = s[i];
      if (m >= 2 and good(v[m - 1], v[m - 2]))
        m -= 2;
    }
    return string(v.begin(), v.begin() + m);
  }
};
