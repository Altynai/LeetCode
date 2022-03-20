struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int maxn = 200004;

  string s;
  struct node {
    // basic fields
    int l, r;
    // maintained fields
    int llen, rlen, longest;

    void set_range(int _l, int _r) { l = _l, r = _r; }

    void set_maintained(int _llen, int _rlen, int _longest) {
      llen = _llen, rlen = _rlen, longest = _longest;
    }

    inline int get_range_size() { return r - l + 1; }

    inline bool is_full() { return get_range_size() == llen; }

  } nodes[maxn << 2];

  void pull(int p) {
    nodes[p].llen = nodes[lson(p)].llen;
    if (nodes[lson(p)].is_full() and s[nodes[lson(p)].l] == s[nodes[rson(p)].l])
      nodes[p].llen = nodes[lson(p)].get_range_size() + nodes[rson(p)].llen;

    nodes[p].rlen = nodes[rson(p)].rlen;
    if (nodes[rson(p)].is_full() and s[nodes[rson(p)].r] == s[nodes[lson(p)].r])
      nodes[p].rlen = nodes[rson(p)].get_range_size() + nodes[lson(p)].rlen;

    nodes[p].longest = max(nodes[lson(p)].longest, nodes[rson(p)].longest);
    if (s[nodes[lson(p)].r] == s[nodes[rson(p)].l])
      nodes[p].longest =
          max(nodes[p].longest, nodes[lson(p)].rlen + nodes[rson(p)].llen);
  }

  void build(int p, int l, int r) {
    nodes[p].set_range(l, r);
    if (l == r) {
      nodes[p].set_maintained(1, 1, 1);
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void update(int p, int pos, char w) {
    if (nodes[p].l == nodes[p].r) {
      s[pos] = w;
      nodes[p].set_maintained(1, 1, 1);
      return;
    }
    int mid = (nodes[p].l + nodes[p].r) >> 1;
    if (pos <= mid)
      update(lson(p), pos, w);
    else
      update(rson(p), pos, w);
    pull(p);
  }

} st;

class Solution {
public:
  vector<int> longestRepeating(string s, string qc, vector<int> &qi) {
    int n = s.size(), m = qc.size();

    st.s = s;
    st.build(1, 0, n - 1);

    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      st.update(1, qi[i], qc[i]);
      ans[i] = st.nodes[1].longest;
    }

    return ans;
  }
};
