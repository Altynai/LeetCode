class Solution {
public:
  bool hasSpecialSubstring(string s, int k) {
    int n = s.size();
    for (int i = 0; i + k <= n; i++) {
      string t = s.substr(i, k);
      if (t != string(k, s[i]))
        continue;
      if (i > 0 and s[i] == s[i - 1])
        continue;
      if (i + k < n and s[i] == s[i + k])
        continue;
      return 1;
    }
    return 0;
  }
};
