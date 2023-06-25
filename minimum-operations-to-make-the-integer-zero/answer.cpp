using int64 = long long;
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    // num1 = k * num2 + (2^m0 + 2^m1 + 2^m(k-1)), we need to minimize k
    // random guess: k should not be over 60
    for (int64 k = 1; k <= 60; k++) {
      int64 sum = 1LL * num1 - k * num2;
      if (sum < k)
        continue;

      int64 cnt = bitCount(sum);
      if (cnt > k)
        continue;
      else if (cnt == k)
        return int(k);
      else {
        // cnt < k, we can split 2^i = 2^(i-1) + 2^(i-1) until i = 0, maximal
        // ways is sum
        if (sum >= k)
          return int(k);
      }
    }
    return -1;
  }
};
