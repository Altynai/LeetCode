class Solution {
public:
  int longestContinuousSubstring(string s) {
    int n = s.size(), ans = 1, now = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1] + 1) {
        now++;
        ans = max(ans, now);
      } else {
        now = 1;
      }
    }
    return ans;
  }
};
