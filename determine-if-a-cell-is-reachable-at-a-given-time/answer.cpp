class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dx = abs(sx - fx), dy = abs(sy - fy);

    int p = t - (dx + dy);
    if (p == 0)
      return 1;

    if (p > 0) {
      if (p % 2 == 0)
        return p > 1;
      else if (dx + dy == 0)
        return p != 1;
      return 1;
    }

    int z = min(dx, dy);
    if (dx + dy - z > t)
      return 0;

    // use one diagonal move
    p = (dx + dy - 2) - (t - 1);
    return p >= 0;
  }
};
