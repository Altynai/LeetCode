#define ll long long

struct RectangleUnionArea {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 20004;

  int nid;
  int y[MAXN << 1];

  struct Line {
    int open; // 1 or -1
    int x, yMax, yMin;
    friend bool operator<(const Line &a, const Line &b) { return a.x < b.x; }

    inline void apply(int _x, int _yMin, int _yMax, int _open) {
      x = _x, yMax = _yMax, yMin = _yMin, open = _open;
    }

  } line[MAXN << 1];

  // NOTICE: the segment is [l, r), so we can connect them in segment tree nodes
  struct SegTree {
    int l, r;
    int cover, len;
  } seg[MAXN << 2];

  void updateLength(int id) {
    if (seg[id].cover > 0)
      seg[id].len = y[seg[id].r] - y[seg[id].l];
    else if (seg[id].l == seg[id].r)
      seg[id].len = 0;
    else
      seg[id].len = seg[lson(id)].len + seg[rson(id)].len;
  }

  void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].cover = 0;
    seg[id].len = 0;
    if (l + 1 < r) {
      int mid = (l + r) >> 1;
      build(lson(id), l, mid);
      build(rson(id), mid, r);
    }
  }

  void update(int id, const Line &ne) {
    if (ne.yMin <= y[seg[id].l] && y[seg[id].r] <= ne.yMax) {
      seg[id].cover += ne.open;
      updateLength(id);
      return;
    }

    if (seg[id].l + 1 == seg[id].r)
      return;

    int mid = (seg[id].l + seg[id].r) >> 1;
    if (ne.yMin <= y[mid])
      update(lson(id), ne);
    if (ne.yMax > y[mid])
      update(rson(id), ne);

    updateLength(id);
  }

  void add(int x1, int y1, int x2, int y2) {
    y[nid] = y1;
    line[nid++].apply(x1, y1, y2, 1);
    y[nid] = y2;
    line[nid++].apply(x2, y1, y2, -1);
  }

  void init() { nid = 0; }

  ll sweep() {
    sort(y, y + nid);
    sort(line, line + nid);

    int m = unique(y, y + nid) - y;
    build(1, 0, m - 1);
    update(1, line[0]);

    ll ans = 0;
    for (int i = 1; i < nid; i++) {
      ans += (ll)seg[1].len * (line[i].x - line[i - 1].x);
      update(1, line[i]);
    }
    return ans;
  }
} rua;

class Solution {
public:
  bool isRectangleCover(vector<vector<int>> &rect) {
    int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
    ll sum = 0;
    for (auto &r : rect) {
      x1 = min(r[0], x1), y1 = min(r[1], y1);
      x2 = max(r[2], x2), y2 = max(r[3], y2);
      sum += 1LL * (r[2] - r[0]) * (r[3] - r[1]);
    }
    if (1LL * (x2 - x1) * (y2 - y1) != sum)
      return false;

    rua.init();
    for (auto &r : rect)
      rua.add(r[0], r[1], r[2], r[3]);
    return rua.sweep() == sum;
  }
};
