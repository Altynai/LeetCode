class Solution {
public:
  int finalPositionOfSnake(int n, vector<string> &commands) {
    int x = 0, y = 0;
    for (string cmd : commands) {
      if (cmd == "UP")
        x--;
      else if (cmd == "DOWN")
        x++;
      else if (cmd == "LEFT")
        y--;
      else
        y++;
    }
    return x * n + y;
  }
};
