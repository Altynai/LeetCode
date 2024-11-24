class Solution {
public:
  bool canAliceWin(int n) {
    int alice = 1, rem = 10;
    while (n >= rem) {
      alice ^= 1;
      n -= rem;
      rem--;
    }
    return alice ^ 1;
  }
};
