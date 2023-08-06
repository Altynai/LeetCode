class Solution {
public:
  int accountBalanceAfterPurchase(int n) {
    int x = n % 10;
    if (x < 5)
      return 100 - (n - x);
    return 100 - (n + 10 - x);
  }
};
