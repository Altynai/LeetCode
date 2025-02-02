class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                  vector<int> &endTime) {
    vector<pair<int, int>> v;
    v.push_back({0, 0});

    int n = startTime.size();
    for (int i = 0; i < n; i++)
      v.push_back({startTime[i], endTime[i]});

    v.push_back({eventTime, eventTime});

    n = v.size();
    vector<int> psum(n, 0);
    for (int i = 0; i < n; i++) {
      psum[i] = v[i].second - v[i].first;
      if (i > 0)
        psum[i] += psum[i - 1];
    }

    int ans = 0;
    for (int i = 1; i + k < n; i++) {
      int duration = psum[i + k - 1] - psum[i - 1];
      int gap = v[i + k].first - v[i - 1].second;
      ans = max(ans, gap - duration);
    }
    return ans;
  }
};
