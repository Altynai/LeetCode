#define lson(i) ((i) * 2)
#define rson(i) ((i) * 2 + 1)

struct Node {
    int l, r;
    int added;
};

class SegmentTree {
public:
    int n, root;
    vector<Node> nodes;
    SegmentTree(int _n) {
        n = _n;
        root = 1;
        nodes.resize(n * 4 + 2);
        build(1, n, root);
    }

    void build(int l, int r, int index) {
        nodes[index].l = l;
        nodes[index].r = r;
        nodes[index].added = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(l, mid, lson(index));
        build(mid + 1, r, rson(index));
    }

    void pushDown(int index) {
        Node& node = nodes[index];
        nodes[lson(index)].added += node.added;
        nodes[rson(index)].added += node.added;
        node.added = 0;
    }

    void update(int l, int r, int value, int index) {
        Node& node = nodes[index];
        if (l == node.l && r == node.r) {
            node.added += value;
            return;
        }
        int mid = (node.l + node.r) >> 1;

        pushDown(index);
        if (r <= mid)
            update(l, r, value, lson(index));
        else if (l >= mid + 1)
            update(l, r, value, rson(index));
        else {
            update(l, mid, value, lson(index));
            update(mid + 1, r, value, rson(index));
        }
    }

    void update(int l, int r, int value) {
        update(l, r, value, root);
    }

    void flush(int l, int r, int index, vector<int>& ans) {
        Node& node = nodes[index];
        if (node.l == node.r) {
            ans.push_back(node.added);
            return;
        }
        int mid = (node.l + node.r) >> 1;
        pushDown(index);
        if (r <= mid)
            flush(l, r, lson(index), ans);
        else if (l >= mid + 1)
            flush(l, r, rson(index), ans);
        else {
            flush(l, mid, lson(index), ans);
            flush(mid + 1, r, rson(index), ans);
        }
    }

    vector<int> flush() {
        vector<int> ans;
        flush(1, n, root, ans);
        return ans;
    }
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        SegmentTree st = SegmentTree(length);
        for (int i = 0; i < updates.size(); ++i) {
            vector<int>& update = updates[i];
            int l = update[0] + 1;
            int r = update[1] + 1;
            int value = update[2];
            st.update(l, r, value);
        }
        return st.flush();
    }
};