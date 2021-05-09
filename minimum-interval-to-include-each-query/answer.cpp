class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &intervals,
                          vector<int> &queries) {
    vector<pair<int, int>> p;
    for (auto &interval : intervals) {
      int size = interval[1] - interval[0] + 1;
      p.emplace_back(interval[0], size);
      p.emplace_back(interval[1] + 1, -size);
    }
    sort(p.begin(), p.end());

    int n = queries.size();
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++)
      q.emplace_back(queries[i], i);
    sort(q.begin(), q.end());

    multiset<int> s;
    vector<int> ans(n, -1);
    for (int i = 0, j = 0; i < n; i++) {
      while (j < p.size() && p[j].first <= q[i].first) {
        int size = p[j].second;
        if (size > 0) {
          s.insert(size);
        } else {
          s.erase(s.find(-size));
        }
        j++;
      }

      if (!s.empty()) {
        ans[q[i].second] = *s.begin();
      }
    }
    return ans;
  }
};
