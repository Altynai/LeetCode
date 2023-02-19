#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int minOperations(int n) {
    int ans = bitCount(n);

    int ops = 0;
    while (n > 0) {
      if ((n & 3) == 3)
        ops++, n++;
      else if (n & 1)
        ops++;
      n /= 2;
    }
    return min(ans, ops);
  }
}
