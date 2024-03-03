template <class T> struct Fenwick {
  vector<T> c;
  int n;

  Fenwick(int _n) {
    n = _n;
    c.resize(_n + 1);
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  inline int lowbit(int x) { return x & (-x); }

  void update(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] = c[i] + val;
  }

  // sum of [1 ... x]
  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret = ret + c[i];
    return ret;
  }
};

template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

class Solution {
public:
  vector<int> resultArray(vector<int> &a) {
    vector<int> b = a;
    int m = deduplicate(b);
    for (int &x : a)
      x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;

    vector<int> arr1 = {a[0]}, arr2 = {a[1]};
    Fenwick<int> bit1(m), bit2(m);
    bit1.update(a[0], 1);
    bit2.update(a[1], 1);

    int n = a.size();
    for (int i = 2; i < n; i++) {
      int cnt1 = arr1.size() - bit1.get(a[i]);
      int cnt2 = arr2.size() - bit2.get(a[i]);
      if (cnt1 > cnt2 or (cnt1 == cnt2 && arr1.size() <= arr2.size()))
        arr1.push_back(a[i]), bit1.update(a[i], 1);
      else
        arr2.push_back(a[i]), bit2.update(a[i], 1);
    }
    for (int x : arr2)
      arr1.push_back(x);

    for (int &x : arr1)
      x = b[x - 1];
    return arr1;
  }
};
