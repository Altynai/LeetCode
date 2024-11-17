template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }
template <class T> bool umin(T &a, const T b) { return a > b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  int minDifference(vector<int> &a) {
    if (*max_element(a.begin(), a.end()) == -1)
      return 0;

    // obviously binary search
    // for some difference D, how to verify?

    // consider range [P, -1, -1, ..., -1, Q]
    // we can find the possible range for each -1
    // this can be done by checking the nearest positive numbers

    // let's merge all possible ranges
    // if there is only one range left, then it's x, we don't care about y
    // if there 2 ranges left, double check abs(x - y)
    // if more than 2 ranges, then impossible

    int n = a.size();

    using Range = pair<int64, int64>;

    auto Intersect = [&](const Range &lh, const Range &rh) -> bool {
      return max(lh.first, rh.first) <= min(lh.second, rh.second);
    };

    auto Merge = [&](const Range &lh, const Range &rh) -> Range {
      return make_pair(max(lh.first, rh.first), min(lh.second, rh.second));
    };

    auto Test = [&](int d) -> bool {
      vector<Range> p(n, {LLONG_MIN, LLONG_MAX});

      int last = -1;
      for (int i = 0; i < n; i++) {
        if (a[i] == -1 and last != -1) {
          int64 distance = i - last;
          umax(p[i].first, 1LL * a[last] - distance * d);
          umin(p[i].second, 1LL * a[last] + distance * d);
        }
        if (a[i] != -1)
          last = i;
      }
      last = -1;
      for (int i = n - 1; i >= 0; i--) {
        if (a[i] == -1 and last != -1) {
          int64 distance = last - i;
          umax(p[i].first, 1LL * a[last] - distance * d);
          umin(p[i].second, 1LL * a[last] + distance * d);
        }
        if (a[i] != -1)
          last = i;
      }

      vector<Range> ranges;
      for (int i = 0; i < n; i++) {
        if (a[i] != -1)
          continue;

        // skip invalid ranges
        if (p[i].first > p[i].second)
          return 0;

        if (ranges.size() == 0)
          ranges.push_back(p[i]);
        else if (ranges.size() == 1) {
          if (Intersect(ranges[0], p[i]))
            ranges[0] = Merge(ranges[0], p[i]);
          else
            ranges.push_back(p[i]);
        } else {
          if (Intersect(ranges[0], p[i]))
            ranges[0] = Merge(ranges[0], p[i]);
          else if (Intersect(ranges[1], p[i]))
            ranges[1] = Merge(ranges[1], p[i]);
          else
            return 0; // need at least 3 numbers
        }
      }

      if (ranges.size() <= 1)
        return 1;
      assert(ranges.size() == 2);

      sort(ranges.begin(), ranges.end());

      last = -1;
      for (int i = 0, mark = -1; i < n; i++) {
        if (a[i] != -1)
          continue;

        int mark2 = (Intersect(ranges[0], p[i])) ? 0 : 1;
        if (last != -1 and last == i - 1 and mark2 != mark)
          return ranges[1].first - ranges[0].second <= d;

        last = i, mark = mark2;
      }

      return 1;
    };

    int l = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] != -1 and a[i - 1] != -1)
        umax(l, abs(a[i] - a[i - 1]));
    }
    int r = *max_element(a.begin(), a.end()) + 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
