struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 50004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int tag[MAXN];
  int val[MAXN];

  inline int rangeSize(int p) { return R[p] - L[p] + 1; }

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r, tag[p] = INT_MAX;
    if (l == r) {
      val[p] = INT_MAX;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void tagNode(int p, int newVal) {
    tag[p] = min(tag[p], newVal);
    val[p] = min(val[p], newVal);
  }

  void push(int p) {
    // can't push down on leaf nodes
    assert(L[p] != R[p]);
    if (tag[p]) {
      tagNode(lson(p), tag[p]);
      tagNode(rson(p), tag[p]);
    }
    tag[p] = INT_MAX;
  }

  void pull(int p) {
    // can't pull on leaf nodes
    assert(L[p] != R[p]);
    val[p] = min(val[lson(p)], val[rson(p)]);
  }

  void rangeUpdate(int p, int l, int r, int newValue) {
    // case 1: update leaf node
    if (L[p] == R[p]) {
      val[p] = min(val[p], newValue);
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      tagNode(p, newValue);
    }
    // case 3: may need to split the range
    else {
      // make sure to call push before doing rangeSet on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        rangeUpdate(lson(p), l, r, newValue);
      else if (l > mid)
        rangeUpdate(rson(p), l, r, newValue);
      else {
        rangeUpdate(lson(p), l, mid, newValue);
        rangeUpdate(rson(p), mid + 1, r, newValue);
      }
      // make sure to call pill after doing rangeSet on child nodes
      pull(p);
    }
  }

  int query(int p, int l, int r) {
    // case 1: query leaf node
    if (L[p] == R[p]) {
      return val[p];
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      return val[p];
    }
    // case 3: may need to split the range
    else {
      // make sure to call push before doing query on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        return query(lson(p), l, r);
      else if (l > mid)
        return query(rson(p), l, r);
      else {
        return min(query(lson(p), l, mid), query(rson(p), mid + 1, r));
      }
    }
  }
} st;

/*
https://oi-wiki.org/string/z-func/

z[i] = LCP(s, s[i, n - 1]), especially: z[0] = 0

z(aaaaa) = [0, 4, 3, 2, 1]
z(aaabaab) = [0, 2, 1, 0, 2, 1, 0]
z(abacaba) = [0, 0, 1, 0, 3, 0, 1]
*/
vector<int> z_function(const string &s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
    }
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

class Solution {
public:
  int minValidStrings(vector<string> &words, string s) {
    /*
     dp[i] = min(dp[j]) + 1, where j < i and s[j + 1 .... i] is valid

     1. quick check "s[j + 1 .... i] is valid"?
     since n <= 100, using z func gives us O(100 * 5 * 10^ 4 + 10^5)
     so for each j + 1, we can find the biggest i based on z func's results
     and perform a range minimal update for dp[j + 1 .... i]

     2. range minimal update?
     easy, lazy segment tree
    */

    int n = words.size();
    vector<vector<int>> z_vals(n);
    for (int i = 0; i < n; i++) {
      string t = words[i] + "#" + s;
      z_vals[i] = z_function(t);
    }

    // return biggest r that s[l ... r] is valid
    // -1 if not found
    auto Search = [&](int l) -> int {
      int res = -1;
      for (int i = 0; i < n; i++) {
        int pos = words[i].size() + 1 + l;
        if (z_vals[i][pos] > 0)
          res = max(res, z_vals[i][pos]);
      }
      if (res == -1)
        return -1;
      return l + res - 1;
    };

    int m = s.size();
    vector<int> dp(m, INT_MAX);
    st.build(1, 0, m - 1);

    int r = Search(0);
    if (r != -1)
      st.rangeUpdate(1, 0, r, 1);

    for (int l = 0; l + 1 < m; l++) {
      dp[l] = st.query(1, l, l);
      if (dp[l] == INT_MAX)
        return -1;

      r = Search(l + 1);
      if (r != -1)
        st.rangeUpdate(1, l + 1, r, dp[l] + 1);
    }

    int res = st.query(1, m - 1, m - 1);
    return res == INT_MAX ? -1 : res;
  }
};
