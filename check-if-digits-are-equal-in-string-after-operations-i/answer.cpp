class Solution {
public:
  bool hasSameDigits(string s) {
    while (s.size() > 2) {
      int n = s.size();
      for (int i = 0; i < n - 1; i++) {
        int x = s[i] - '0';
        int y = s[i + 1] - '0';
        s[i] = '0' + (x + y) % 10;
      }
      s.pop_back();
    }
    return s[0] == s[1];
  }
};
