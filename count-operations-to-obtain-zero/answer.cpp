class Solution {
public:
  int countOperations(int x, int y) {
    int ans = 0;
    while (x > 0 and y > 0) {
      if (x >= y)
        x -= y;
      else
        y -= x;
      ans++;
    }
    return ans;
  }
};
