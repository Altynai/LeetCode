class Solution {
public:
  int countHomogenous(string s) {
    const int mod = 1e9 + 7;
    int cnt = 0, ans = 0;
    char pre = '?';
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] != pre) {
        ans += 1LL * (cnt + 1) * cnt / 2 % mod;
        ans %= mod;
        cnt = 1;
        pre = s[i];
      } else {
        cnt++;
      }
    }
    ans += 1LL * (cnt + 1) * cnt / 2 % mod;
    ans %= mod;
    return ans;
  }
};
