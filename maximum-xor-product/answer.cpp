#define bit(n, i) (((n) >> (i)) & 1)

const int N = 50;
const int MOD = 1e9 + 7;

using int64 = long long;

class Solution {
public:
  int maximumXorProduct(long long a, long long b, int n) {
    vector<int64> diffs;
    for (int i = n - 1; i >= 0; i--) {
      if (bit(a, i) != bit(b, i)) {
        diffs.push_back(1LL << i);
        if (bit(a, i) == 1)
          a ^= 1LL << i;
        if (bit(b, i) == 1)
          b ^= 1LL << i;
      } else {
        if (bit(a, i) == 0)
          a |= 1LL << i;
        if (bit(b, i) == 0)
          b |= 1LL << i;
      }
    }

    for (int64 x : diffs) {
      if (a < b)
        swap(a, b);
      b += x;
    }
    return (a % MOD) * (b % MOD) % MOD;
  }
};
