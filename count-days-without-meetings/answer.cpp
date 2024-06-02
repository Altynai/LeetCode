class Solution {
public:
  int countDays(int days, vector<vector<int>> &meetings) {
    vector<pair<int, int>> v;
    for (auto &meeting : meetings) {
      v.push_back({meeting[0], +1});
      v.push_back({meeting[1], -1});
    }

    sort(v.begin(), v.end());
    int n = v.size(), ans = 0, cnt = 0;
    int last = 0;
    for (int i = 0; i < n;) {
      int j = i, prev = cnt;
      while (j < n and v[j].first == v[i].first)
        cnt += v[j++].second;
      if (prev == 0)
        ans += v[i].first - last - 1;
      if (cnt == 0)
        last = v[i].first;
      i = j;
    }

    ans += days - v[n - 1].first;
    return ans;
  }
};
