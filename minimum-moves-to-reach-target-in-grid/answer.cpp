class Solution {
public:
  int minMoves(int sx, int sy, int tx, int ty) {
    int ans = 0;
    while (tx > sx or ty > sy) {
      if (ty > tx)
        swap(tx, ty), swap(sx, sy);
      if (tx == ty) {
        if (sx == 0)
          tx = 0;
        else
          ty = 0;
      } else {
        if (tx >= ty * 2) {
          if (tx & 1)
            return -1;
          tx /= 2;
        } else
          tx -= ty;
      }
      ans++;
    }
    return tx < sx or ty < sy ? -1 : ans;
  }
};
