struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 50004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int tag[MAXN];
  int mx[MAXN];

  inline int rangeSize(int p) { return R[p] - L[p] + 1; }

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r, tag[p] = 0;
    if (l == r) {
      mx[p] = 0;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void tagNode(int p, int newVal) {
    tag[p] += newVal;
    mx[p] += newVal;
  }

  void push(int p) {
    // can't push down on leaf nodes
    assert(L[p] != R[p]);
    if (tag[p] != 0) {
      tagNode(lson(p), tag[p]);
      tagNode(rson(p), tag[p]);
    }
    tag[p] = 0;
  }

  void pull(int p) {
    // can't pull on leaf nodes
    assert(L[p] != R[p]);
    mx[p] = max(mx[lson(p)], mx[rson(p)]);
  }

  void rangeUpdate(int p, int l, int r, int newValue) {
    // case 1: update leaf node
    if (L[p] == R[p]) {
      mx[p] += newValue;
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
      return mx[p];
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      return mx[p];
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
        return max(query(lson(p), l, mid), query(rson(p), mid + 1, r));
      }
    }
  }
} st;

struct PrimeFactorization {

  // primes.size() <= sqrt(n)
  vector<int> primes;
  vector<bool> p;

  PrimeFactorization(int n) {
    p.resize(n);
    p.assign(n, true);

    p[0] = p[1] = 0;
    for (int i = 4; i < n; i += 2)
      p[i] = 0;
    for (int i = 3; i * i < n; i += 2) {
      if (!p[i])
        continue;
      for (int j = i * i; j < n; j += i)
        p[j] = 0;
    }

    primes = {2};
    for (int i = 3; i < n; i += 2)
      if (p[i])
        primes.push_back(i);
  }

  vector<pair<int, int>> getFactors(int n) {
    vector<pair<int, int>> ans;
    for (int i = 0; n > 1 && i < (int)primes.size(); i++) {
      int cnt = 0;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      if (cnt)
        ans.emplace_back(primes[i], cnt);
    }
    if (n > 1)
      ans.emplace_back(n, 1);
    return ans;
  }
} pf(1e5 + 1);

class Solution {
public:
  vector<int> maximumCount(vector<int> &a, vector<vector<int>> &queries) {
    const vector<bool> is_prime = pf.p;

    int n = a.size();
    unordered_map<int, set<int>> where;
    for (int i = 0; i < n; i++) {
      if (is_prime[a[i]])
        where[a[i]].insert(i);
    }

    st.build(1, 0, n - 1);

    // val = +1/-1
    auto Update = [&](int prime, const set<int> &indices, int val) {
      int m = indices.size();
      if (m == 0)
        return;
      else if (m == 1)
        st.rangeUpdate(1, 0, n - 2, val);
      else {
        int l = *indices.begin();
        int r = *prev(indices.end());
        st.rangeUpdate(1, 0, n - 2, val);
        st.rangeUpdate(1, l, r - 1, val);
      }
    };

    for (auto [val, indices] : where) {
      if (is_prime[val])
        Update(val, indices, +1);
    }

    int q = queries.size();
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
      int j = queries[i][0], new_val = queries[i][1];
      int old_val = a[j];
      if (old_val != new_val) {
        vector<int> candidates = {old_val, new_val};
        for (int x : candidates) {
          if (is_prime[x]) {
            Update(x, where[x], -1);
            where[x].erase(j);
          }
        }
        a[j] = new_val;
        where[new_val].insert(j);
        for (int x : candidates) {
          if (is_prime[x])
            Update(x, where[x], +1);
        }
      }
      ans[i] = st.query(1, 0, n - 2);
    }
    return ans;
  }
};
