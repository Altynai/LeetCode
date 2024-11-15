class Solution {
public:
  int smallestNumber(int n, int t) {
    int res = 1;
    for (int x = n; x > 0; x /= 10) {
      int y = x % 10;
      res = res * y % t;
    }
    return res == 0 ? n : smallestNumber(n + 1, t);
  }
};
