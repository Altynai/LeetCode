class Solution {
public:
  int distMoney(int money, int children) {
    int ans = -1;
    for (int i = 0; i <= min(children, money / 8); ans = i++) {
      int left = money - i * 8;
      int n = children - i;

      // at least 1 dollar
      left -= n;
      if (left < 0)
        break;

      if (n == 0 and left > 0)
        break;

      // nobody gets 3
      if (left != 3)
        continue;

      if (n == 1)
        break;
    }
    return ans;
  }
};
