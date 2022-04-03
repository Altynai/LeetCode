class Solution {
public:
  long long numberOfWays(string s) {
    long long ans = 0;
    int n = s.size();
    for (int k = 0; k <= 1; k++) {
      vector<int> pref(n + 1, 0), suf(n + 2, 0);
      for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + (s[i - 1] - '0' == k);
      }
      for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + (s[i - 1] - '0' == k);
      }
      for (int i = 1; i <= n; i++) {
        if (s[i - 1] - '0' == (k ^ 1)) {
          ans += 1LL * pref[i - 1] * suf[i + 1];
        }
      }
    }
    return ans;
  }
};
