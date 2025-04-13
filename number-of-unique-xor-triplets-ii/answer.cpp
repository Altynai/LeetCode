#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int uniqueXorTriplets(vector<int> &a) {
    int n = a.size();

    // find max possible value
    int msb = 0;
    for (int i = 0; i < 20; i++) {
      for (int x : a) {
        if (bit(x, i))
          msb = i;
      }
    }
    int N = 1 << (msb + 1);

    vector<bool> dp(N, 0);
    vector<int> seen(N, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++)
        dp[a[i] ^ a[j]] = 1;
      for (int x = 0; x < N; x++) {
        if (dp[x])
          seen[x ^ a[i]] = 1;
      }
    }

    return accumulate(seen.begin(), seen.end(), 0);
  }
};
