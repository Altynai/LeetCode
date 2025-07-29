class Solution {
public:
  bool checkDivisibility(int n) {
    int p = 1, sum = 0;
    for (int m = n; m > 0; m /= 10) {
      sum += m % 10;
      p *= m % 10;
    }
    return n % (sum + p) == 0;
  }
};
