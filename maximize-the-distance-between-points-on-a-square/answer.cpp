using int64 = long long;

class Solution {
public:
  int maxDistance(int side, vector<vector<int>> &p, int k) {
    int n = p.size();
    vector<pair<int64, int>> v(n);
    for (int i = 0; i < n; i++) {
      int x = p[i][0], y = p[i][1];
      if (x == 0)
        v[i] = {y, i};
      else if (y == side)
        v[i] = {side + x, i};
      else if (x == side)
        v[i] = {2LL * side + (side - y), i};
      else
        v[i] = {3LL * side + (side - x), i};
    }
    sort(v.begin(), v.end());

    auto Test = [&](int d) -> bool {
      for (int i = 0; i < n; i++) {
        int cur = i;
        bool good = 1;
        for (int t = 0; good and t < k - 1; t++) {
          int pos = -1;
          for (int l = cur + 1, r = n - 1; l <= r;) {
            int mid = (l + r) / 2;
            if (v[mid].first >= v[cur].first + d)
              pos = mid, r = mid - 1;
            else
              l = mid + 1;
          }
          if (pos == -1)
            good = 0;
          else
            cur = pos;
        }
        if (!good)
          continue;

        // check head and tail
        int dis = abs(p[v[i].second][0] - p[v[cur].second][0]);
        dis += abs(p[v[i].second][1] - p[v[cur].second][1]);
        if (dis >= d) {
          return 1;
        }
      }
      return 0;
    };

    int ans = -1;
    for (int l = 1, r = side; l <= r;) {
      int mid = (l + r) / 2;
      if (Test(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
