class Solution {
public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n & 1)
      return 0;

    int wild = 0, open = 0, close = 0;
    for (int i = 0; i < n; i++) {
      if (locked[i] == '0')
        wild++;
      else if (s[i] == '(')
        open++;
      else
        close++;

      if (wild + open < close)
        return 0;
    }

    wild = 0, open = 0, close = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (locked[i] == '0')
        wild++;
      else if (s[i] == ')')
        open++;
      else
        close++;

      if (wild + open < close)
        return 0;
    }
    return 1;
  }
};
