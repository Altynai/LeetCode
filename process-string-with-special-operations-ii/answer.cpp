using int64 = long long;

class Solution {
public:
  char processStr(string s, long long k) {
    int n = s.size();
    int64 len = 0;
    for (char c : s) {
      if (c == '*')
        len = max(len - 1, 0LL);
      else if (c == '#')
        len *= 2;
      else if (c != '%')
        len++;
    }
    if (k >= len)
      return '.';

    for (int i = n - 1; i >= 0; i--) {
      char c = s[i];
      if (c == '*')
        len++;
      else if (c == '#') {
        len /= 2;
        if (k >= len)
          k -= len;
      } else if (c == '%')
        k = len - 1 - k;
      else {
        len--;
        if (len == k)
          return c;
      }
    }
    return '.';
  }
};
