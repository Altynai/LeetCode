const string SEP = "!@#$%^&*()-+";

class Solution {
public:
  bool strongPasswordCheckerII(string s) {
    int n = s.size();
    if (n < 8)
      return 0;
    for (int i = 1; i < n; i++)
      if (s[i] == s[i - 1])
        return 0;

    bool low = 0, up = 0, dig = 0, sep = 0;
    for (int i = 0; i < n; i++) {
      if (islower(s[i]))
        low = 1;
      if (isupper(s[i]))
        up = 1;
      if (isdigit(s[i]))
        dig = 1;
      if (SEP.find(s[i]) != -1)
        sep = 1;
    }
    return low and up and dig and sep;
  }
};
