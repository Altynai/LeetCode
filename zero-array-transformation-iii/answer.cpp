using Range = pair<int, int>;

struct RangeCmp {
  bool operator()(const Range &lhs, const Range &rhs) const {
    if (lhs.second != rhs.second)
      return lhs.second > rhs.second;
    return lhs.first < rhs.first;
  }
};

class Solution {
public:
  int maxRemoval(vector<int> &a, vector<vector<int>> &queries) {
    // we can sort ranges by L, choose larger R first to cover more indices
    // then maintain a set of valid ranges which covers current position i
    // if we need more ranges, always choose the largest R first

    int n = a.size(), m = queries.size();
    sort(queries.begin(), queries.end(), [](auto &lhs, auto &rhs) {
      if (lhs[0] != rhs[0])
        return lhs[0] < rhs[0];
      return lhs[1] > rhs[1];
    });

    vector<int> sum(n + 1, 0);
    multiset<Range, RangeCmp> ranges;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      while (j < m and queries[j][0] == i) {
        ranges.insert({queries[j][0], queries[j][1]});
        j++;
      }

      if (i > 0)
        sum[i] += sum[i - 1];
      if (sum[i] < a[i]) {
        int need = a[i] - sum[i];
        while (need > 0 and ranges.size() > 0) {
          auto [l, r] = *ranges.begin();
          ranges.erase(ranges.begin());
          if (r < i)
            continue;

          sum[i] += 1, sum[r + 1] -= 1;
          need--, ans++;
        }
        if (need > 0)
          return -1;
      }
    }
    return m - ans;
  }
};
