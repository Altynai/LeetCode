#define N 205
#define ll long long
int n, nid;
int y[N * 2];
const ll mod = 1000000000 + 7;

struct Line {
    int f;
    int x, uy, dy;
    friend bool operator<(const Line& a, const Line& b) {
        return a.x < b.x;
    }
} line[N * 2];

struct SegTree {
    int l, r, cover, len;
} seg[N * 4];

void getlength(int id) {
    if (seg[id].cover > 0) //整段被覆盖
        seg[id].len = y[ seg[id].r ] - y[ seg[id].l ];
    else if (seg[id].l + 1 == seg[id].r) //只是一个点
        seg[id].len = 0;
    else
        seg[id].len = seg[id << 1].len + seg[id << 1 | 1].len;
}

void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].cover = 0;
    seg[id].len = 0;

    if (l + 1 < r) {
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid, r);
    }
}

void update(int id, Line ne) {
    if (ne.dy <= y[ seg[id].l ] && y[ seg[id].r ] <= ne.uy) {
        seg[id].cover += ne.f;
        getlength(id);
        return;
    }

    if (seg[id].l + 1 == seg[id].r)
        return;
    int mid = (seg[id].l + seg[id].r) >> 1;

    if (ne.dy <= y[mid])
        update(id << 1, ne);
    if (ne.uy > y[mid])
        update(id << 1 | 1, ne);

    getlength(id);
}


void add(int x1, int y1, int x2, int y2) {
    y[nid] = y1;
    line[nid].x = x1;
    line[nid].f = 1;
    line[nid].dy = y1;
    line[nid].uy = y2;
    nid++;

    y[nid] = y2;
    line[nid].x = x2;
    line[nid].f = -1;
    line[nid].dy = y1;
    line[nid].uy = y2;
    nid++;
}

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        nid = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll x1 = rectangles[i][0];
            ll y1 = rectangles[i][1];
            ll x2 = rectangles[i][2];
            ll y2 = rectangles[i][3];
            add(x1, y1, x2, y2);
        }
        sort(y, y + nid);
        sort(line, line + nid);
        int ynum = unique(y, y + nid) - y;
        build(1, 0, ynum - 1);
        update(1, line[0]);
        for (int i = 1; i < nid; i++) {
            ans += (ll)seg[1].len * (ll)(line[i].x - line[i - 1].x);
            ans %= mod;
            update(1, line[i]);
        }
        return (ans + mod) % mod;
    }
};
