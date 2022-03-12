template <class T> inline bool umin(T &a, const T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class RangeModule {
private:
  map<int, int> ranges;

public:
  RangeModule() { ranges.clear(); }

  void addRange(int l, int r) {
    umax(ranges[l], r);
    r = ranges[l];

    // merge left
    auto it = ranges.lower_bound(l);
    if (it != ranges.begin()) {
      it = prev(it);
      auto [x, y] = *it;

      // [x, l <= y, r)
      if (l <= y) {
        umax(ranges[x], max(r, y));
        ranges.erase(l);
        l = x, r = max(r, y);
      }
    }

    // merge right
    while (true) {
      auto it = ranges.lower_bound(l);
      assert(it != ranges.end());
      it = next(it);
      if (it == ranges.end())
        break;
      auto [x, y] = *it;
      // [l, r) .. [x, y)
      if (r < x)
        break;

      umax(ranges[l], max(r, y));
      ranges.erase(x);
      r = max(r, y);
    }
  }

  bool queryRange(int l, int r) {
    auto it = ranges.lower_bound(l);
    if (it->first == l)
      return it->second >= r;
    if (it == ranges.begin())
      return 0;

    it = prev(it);
    return it->second >= r;
  }

  void removeRange(int l, int r) {
    // remove left
    auto it = ranges.lower_bound(l);
    if (it != ranges.begin()) {
      it = prev(it);
      auto [x, y] = *it;
      // [x < l < y ..)
      if (l < y) {
        ranges[x] = l;
        if (r < y)
          ranges[r] = y;
      }
    }
    // remove right
    while (true) {
      it = ranges.lower_bound(l);
      if (it == ranges.end())
        break;

      auto [x, y] = *it;
      // [l, r <= x < y)
      if (r <= x)
        break;

      // [l, x < y <= r
      if (r >= y)
        ranges.erase(it);
      else {
        ranges.erase(it);
        ranges[r] = y;
        break;
      }
    }
  }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(l,r);
 * bool param_2 = obj->queryRange(l,r);
 * obj->removeRange(l,r);
 */
