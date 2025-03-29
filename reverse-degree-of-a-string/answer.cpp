class Solution {
public:
  int reverseDegree(string s) {
    int ans = 0, n = s.size();
    for (int i = 1; i <= n; i++) {
      int x = s[i - 1] - 'a';
      ans += i * (26 - x);
    }
    return ans;
  }
};
