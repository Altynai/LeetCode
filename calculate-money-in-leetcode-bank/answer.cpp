class Solution {
public:
  int totalMoney(int n) {
    int s = 0, monday = 0, now = 0;
    for (int i = 1; i <= n; i++) {
      if (i % 7 == 1) {
        now = ++monday;
      } else {
        now++;
      }
      s += now;
    }
    return s;
  }
};
