class Solution {
public:
  string makeSmallestPalindrome(string s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
      s[i] = s[j] = min(s[i], s[j]);
    }
    return s;
  }
};
