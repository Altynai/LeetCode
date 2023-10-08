#define bit(n, i) (((n) >> (i)) & 1)

const int MOD = 1e9 + 7;

class Solution {
public:
  int maxSum(vector<int> &a, int k) {
    // 11 -> 11
    // 10 -> 01
    // 01 -> 01
    // 00 -> 00

    vector<int> b(k, 0);
    for (int i = 30; i >= 0; i--) {
      int cnt = 0;
      for (int x : a)
        cnt += bit(x, i);
      for (int j = 0; j < min(cnt, k); j++)
        b[j] |= (1 << i);
    }

    long long ans = 0;
    for (int x : b) {
      ans += 1LL * x * x;
      ans %= MOD;
    }
    return ans;
  }
};
