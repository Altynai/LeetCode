class CountIntervals {
  int len;
  multiset<pair<int, int>> intervals;

public:
  CountIntervals() {
    len = 0;
    intervals.clear();
  }

  void add(int l, int r) {
    auto it = intervals.insert({l, r});
    len += r - l + 1;

    // forward
    while (it != intervals.end()) {
      auto next_ptr = next(it);
      auto [p, q] = *next_ptr;

      if (max(l, p) > min(r, q))
        break;

      len -= (q - p + 1);
      intervals.erase(next_ptr);
      len -= (r - l + 1);
      intervals.erase(it);

      l = min(l, p);
      r = max(r, q);
      it = intervals.insert({l, r});
      len += r - l + 1;
    }

    // backward
    while (it != intervals.begin()) {
      auto prev_ptr = prev(it);
      auto [p, q] = *prev_ptr;

      if (max(l, p) > min(r, q))
        break;

      len -= (q - p + 1);
      intervals.erase(prev_ptr);
      len -= (r - l + 1);
      intervals.erase(it);

      l = min(l, p);
      r = max(r, q);
      it = intervals.insert({l, r});
      len += r - l + 1;
    }
  }

  int count() { return len; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
