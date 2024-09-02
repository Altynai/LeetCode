class Solution {
public:
  int generateKey(int a, int b, int c) {
    int ans = 0, ten = 1;
    for (int i = 0; i < 4; i++) {
      int p = min(min(a % 10, b % 10), c % 10);
      ans += p * ten;
      ten *= 10;
      a /= 10, b /= 10, c /= 10;
    }
    return ans;
  }
};
