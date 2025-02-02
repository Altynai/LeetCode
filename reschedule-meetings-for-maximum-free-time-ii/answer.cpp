class Solution {
public:
  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    vector<pair<int, int>> v;
    v.push_back({0, 0});

    int n = startTime.size();
    for (int i = 0; i < n; i++)
      v.push_back({startTime[i], endTime[i]});

    v.push_back({eventTime, eventTime});

    n = v.size();
    multiset<int> s;
    for (int i = 1; i < n; i++)
      s.insert(v[i].first - v[i - 1].second);

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      int gap0 = v[i].first - v[i - 1].second;
      int duration = v[i].second - v[i].first;
      int gap1 = v[i + 1].first - v[i].second;

      s.erase(s.find(gap0));
      s.erase(s.find(gap1));

      if (s.lower_bound(duration) != s.end())
        ans = max(ans, gap0 + duration + gap1);
      else
        ans = max(ans, gap0 + gap1);

      s.insert(gap0);
      s.insert(gap1);
    }
    return ans;
  }
};
