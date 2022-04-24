class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &f, vector<int> &p) {
    int n = f.size();
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
      events.emplace_back(f[i][0], 1);
      events.emplace_back(f[i][1] + 1, -1);
    }

    sort(events.begin(), events.end());

    map<int, int> cnt;
    cnt[0] = 0;

    int m = events.size();
    for (int i = 0, sum = 0; i < m;) {
      int j = i;
      while (j < m and events[j].first == events[i].first)
        sum += events[j++].second;
      cnt[events[i].first] = sum;
      i = j;
    }

    m = p.size();
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
      auto it = cnt.lower_bound(p[i]);
      if (it != cnt.end()) {
        if (it->first == p[i])
          ans[i] = it->second;
        else if (it != cnt.begin())
          ans[i] = prev(it)->second;
      }
    }
    return ans;
  }
};
