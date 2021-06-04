class Solution {
public:
  int countGoodSubstrings(string s) {
    int n = s.size(), ans = 0;
    for (int i = 0; i + 2 < n; i++) {
      if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
        ans++;
    }
    return ans;
  }
};
