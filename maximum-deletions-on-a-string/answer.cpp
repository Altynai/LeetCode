const unsigned SEED = chrono::steady_clock::now().time_since_epoch().count();

/*
Tips:
1. for hashing multiple set, don't use "Sum" directly, consider using sum of x^2
+ x + 1 or even higher polynomial
   * source:
https://stackoverflow.com/questions/36520235/algorithm-for-hash-crc-of-unordered-multiset
   * good custom hash blog from neal_wu: https://codeforces.com/blog/entry/62393
   * another idea of using XOR hashing: https://codeforces.com/blog/entry/85900
*/
uint64_t get_hash(int v) {
  uint64_t x = (uint64_t)v + SEED;
  // http://xorshift.di.unimi.it/splitmix64.c
  uint64_t z = (x += 0x9e3779b97f4a7c15);
  z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
  z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
  return z ^ (z >> 31);
}

const uint64_t P = 1e9 + 7;

class Solution {
public:
  int deleteString(string s) {
    int n = s.size();

    vector<vector<uint64_t>> h(n, vector<uint64_t>(n));
    for (int i = 0; i < n; i++) {
      uint64_t val = 0;
      for (int j = i; j < n; j++) {
        val = val * P + get_hash(s[j]);
        h[i][j] = val;
      }
    }

    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
      // operation 2
      for (int j = i; j < n; j++) {
        int len = j - i + 1;
        int k = i + len * 2 - 1;
        if (k < n and h[i][j] == h[j + 1][k]) {
          if (i == 0 or dp[i - 1] != -1)
            dp[j] = max(dp[j], (i ? dp[i - 1] : 0) + 1);
        }
      }
      // operation 1
      if (i == 0 or dp[i - 1] != -1)
        dp[n - 1] = max(dp[n - 1], (i ? dp[i - 1] : 0) + 1);
    }
    return dp[n - 1];
  }
};
