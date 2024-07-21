class Solution {
public:
  string losingPlayer(int x, int y) {
    int win = 0;
    while (x >= 1 and y >= 4)
      x--, y -= 4, win ^= 1;
    return win ? "Alice" : "Bob";
  }
};
