using int64 = long long;
constexpr int N = 4e5 + 3;

int a[N * 2], tot;        // a[] 和 tot 用于把 x 离散化
int64 v[N * 8], w[N * 8]; // 完全覆盖区间的次数、已覆盖的长度

struct St {
  int64 x1, x2, y, o; // o (open): +1/-1
} b[N * 2];           // 矩形上下边缘

int f(int y) { // 离散化，把坐标映射到 a 中的下标
  return std::lower_bound(a, a + tot, y) - a;
}

void up(int u, int ul, int ur) { // pushup
  if (v[u])
    w[u] = a[ur] - a[ul];
  // 如果对叶子节点调用 w[u*2+1]，那么线段树需要开 8 倍空间
  // 乘上矩形上下两边就是 16 倍
  else if (ul + 1 == ur)
    w[u] = 0;
  else
    w[u] = w[u * 2 + 1] + w[u * 2 + 2];
}

void add(int lf, int rg, int64 o, int u = 0, int ul = 0, int ur = tot - 1) {
  // 区间加
  if (lf == ul && rg == ur)
    return v[u] += o, up(u, ul, ur), void();
  int um = (ul + ur) / 2;
  if (lf < um)
    add(lf, std::min(rg, um), o, u * 2 + 1, ul, um);
  if (um < rg)
    add(std::max(lf, um), rg, o, u * 2 + 2, um, ur);
  up(u, ul, ur);
}

class Solution {
public:
  double separateSquares(vector<vector<int>> &sq) {

    int n = sq.size();

    // init
    for (int i = 0; i < n * 8; i++)
      v[i] = w[i] = 0;

    for (int i = 0, x1, x2, y1, y2; i < n; i++) {
      x1 = sq[i][0], x2 = sq[i][0] + sq[i][2];
      y1 = sq[i][1], y2 = sq[i][1] + sq[i][2];

      b[i] = {x1, x2, y1, 1};
      b[i + n] = {x1, x2, y2, -1};
      a[i] = x1, a[i + n] = x2;
    }
    std::sort(a, a + n * 2), tot = 1;
    for (int i = 1; i < n * 2; i++) {
      if (a[i] != a[tot - 1])
        a[tot++] = a[i]; // 离散化
    }

    std::sort(b, b + n * 2,
              [](St &i, St &j) -> bool { return i.y < j.y; }); // 操作排序

    int64 sum = 0;
    add(f(b[0].x1), f(b[0].x2), 1);
    for (int i = 1; i < n * 2; i++) {
      int x1 = f(b[i].x1), x2 = f(b[i].x2);
      sum += (b[i].y - b[i - 1].y) * w[0]; // 对每个小矩形面积求和
      add(x1, x2, b[i].o);
    }

    double area = 0, half = (double)sum / 2.0;
    add(f(b[0].x1), f(b[0].x2), 1);
    for (int i = 1; i < n * 2; i++) {
      double prev_area = area;
      int x1 = f(b[i].x1), x2 = f(b[i].x2);
      area += (b[i].y - b[i - 1].y) * w[0]; // 对每个小矩形面积求和
      if (prev_area < half and area >= half) {
        return (double)b[i - 1].y + (half - prev_area) / w[0];
      }
      add(x1, x2, b[i].o);
    }
    return -1;
  }
};
