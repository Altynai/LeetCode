class Solution {
public:
  bool isReachable(int x, int y) {
    while (x % 2 == 0)
      x /= 2;
    while (y % 2 == 0)
      y /= 2;
    return gcd(x, y) == 1;
  }
};
