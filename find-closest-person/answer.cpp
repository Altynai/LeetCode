class Solution {
public:
  int findClosest(int x, int y, int z) {
    int tx = abs(x - z), ty = abs(y - z);
    if (tx == ty)
      return 0;
    return tx < ty ? 1 : 2;
  }
};
