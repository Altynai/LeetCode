class Solution {
public:
  int longestSemiRepetitiveSubstring(string s) {
    int n = s.size();
    for (int len = n; len >= 1; len--) {
      for (int i = 0, j = i + len - 1; j < n; i++, j++) {
        int cnt = 0;
        for (int k = i + 1; k <= j; k++) {
          if (s[k] == s[k - 1])
            cnt++;
        }
        if (cnt < 2)
          return len;
      }
    }
    return -1;
  }
};
