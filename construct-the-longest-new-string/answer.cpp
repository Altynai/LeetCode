class Solution {
public:
  int longestString(int x, int y, int z) {
    // not allowed: xx, xz, yy, zy
    // allowed xy, yx, yz, zx, zz
    // z can be placed anywhere
    int cnt = min(x, y) * 2;
    if (x != y)
      cnt++;
    return (cnt + z) * 2;
  }
};
