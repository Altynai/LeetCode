class Solution {
public:
  int countPalindromicSubsequence(string s) {
    const int N = 26;
    int ans = 0, n = s.size();
    for (int i = 0; i < N; i++) {
      int l = 0, r = n - 1;
      while (l < n && s[l] - 'a' != i)
        l++;
      while (r >= 0 && s[r] - 'a' != i)
        r--;
      if (l < r) {
        ans += unordered_set<char>(s.begin() + l + 1, s.begin() + r).size();
      }
    }
    return ans;
  }
};
