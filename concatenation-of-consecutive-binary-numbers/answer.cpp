class Solution {
public:
  int concatenatedBinary(int n) {
    int mod = 1e9 + 7;
    int ans = 0, pow = 1;
    for (int j = n; j >= 1; j--) {
      int i = j;
      while (i > 0) {
        if (i & 1) {
          ans = (1LL * ans + pow) % mod;
        }
        i /= 2;
        pow = 2LL * pow % mod;
      }
    }
    return ans;
  }
};
