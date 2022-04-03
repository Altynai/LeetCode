#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int minBitFlips(int a, int b) { return bitCount(a ^ b); }
};
