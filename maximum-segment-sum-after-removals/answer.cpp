using int64 = long long;

class Solution {
public:
  vector<int64> maximumSegmentSum(vector<int> &a, vector<int> &q) {
    int n = a.size();
    vector<int64> psum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      psum[i] = psum[i - 1] + a[i - 1];

    multiset<int64> sums;
    set<pair<int, int>> ranges;

    ranges.insert({1, n});
    sums.insert(psum[n]);

    auto cut = [&](int x) -> int64 {
      auto it = ranges.upper_bound({x, INT_MAX});
      assert(it != ranges.begin());
      it = prev(it);

      auto [l, r] = *it;
      assert(l <= x and x <= r);
      // remove old seg
      ranges.erase(it);
      sums.erase(sums.find(psum[r] - psum[l - 1]));

      // add 2 new segs
      if (x > l) {
        ranges.insert({l, x - 1});
        sums.insert(psum[x - 1] - psum[l - 1]);
      }
      if (x < r) {
        ranges.insert({x + 1, r});
        sums.insert(psum[r] - psum[x]);
      }

      if (sums.size())
        return *prev(sums.end());
      return 0;
    };

    vector<int64> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = cut(q[i] + 1);
    return ans;
  }
};
