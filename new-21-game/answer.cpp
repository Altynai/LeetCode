
#define M 20002
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1)

int n;

struct Node {
    double add, sum;
    int l, r;
} seg[M << 2];

void build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].add = 0;
    seg[id].sum = 0;
    if (l != r) {
        int mid = (l + r) >> 1;
        build(lson(id), l, mid);
        build(rson(id), mid + 1, r);
    }
}

void update(int id, int l, int r, double w) {
    if (seg[id].l == l && seg[id].r == r) {
        seg[id].add += w;
        seg[id].sum += w * (r - l + 1);
        return;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (r <= mid)
        update(lson(id), l, r, w);
    else if (l > mid)
        update(rson(id), l, r, w);
    else {
        update(lson(id), l, mid, w);
        update(rson(id), mid + 1, r, w);
    }
    seg[id].sum = seg[lson(id)].sum + seg[rson(id)].sum;
}

double query(int id, int l, int r) {
    if (seg[id].l == l && seg[id].r == r) {
        return seg[id].sum;
    }
    if (seg[id].add) {
        seg[lson(id)].add += seg[id].add;
        seg[lson(id)].sum += seg[id].add * (seg[lson(id)].r - seg[lson(id)]. l + 1);
        seg[rson(id)].add += seg[id].add;
        seg[rson(id)].sum += seg[id].add * (seg[rson(id)].r - seg[rson(id)]. l + 1);
        seg[id].add = 0;
    }
    int mid = (seg[id].l + seg[id].r) >> 1;
    if (r <= mid)
        return query(lson(id), l, r);
    else if (l > mid)
        return query(rson(id), l, r);
    else
        return query(lson(id), l, mid) + query(rson(id), mid + 1, r);
}

class Solution {
public:
    double new21Game(int N, int K, int W) {
        n = N + W;
        build(1, 1, n);
        double ratio = 1.0 / (double)(W);
        for (int i = 0; i < K; i++) {
            double p = (i == 0) ? 1.0 : query(1, i, i);
            double add = p * ratio;
            update(1, i + 1, i + W, add);
        }
        if (K == 0)
            return 1.0;
        return query(1, K, N);
    }
};
