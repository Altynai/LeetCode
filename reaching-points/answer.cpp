class Solution {
public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    while (sx < tx or sy < ty) {
      if (tx == 0 or ty == 0)
        break;
      if (tx < ty) {
        int k = max(1, (ty - sy) / tx);
        ty -= k * tx;
      } else {
        int k = max(1, (tx - sx) / ty);
        tx -= k * ty;
      }
    }
    return sx == tx and sy == ty;
  }
};
