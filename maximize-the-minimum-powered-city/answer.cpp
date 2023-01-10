using int64 = long long;

class Solution {
public:
  int64 maxPower(vector<int> &s, int r, int k) {
    int n = s.size();
    int64 ans = -1;

    auto test = [&](int64 x) -> bool {
      deque<pair<int, int64>> q;
      int64 sum = 0, y = k;

      for (int i = 0; i < r; i++) {
        q.push_back({i, s[i]});
        sum += s[i];
      }

      for (int i = 0; i < n; i++) {
        while (q.size() and q.front().first < i - r) {
          sum -= q.front().second;
          q.pop_front();
        }

        if (i + r < n) {
          q.push_back({i + r, s[i + r]});
          sum += s[i + r];
        }

        if (sum < x and y > 0) {
          int64 can = min(y, x - sum);
          y -= can;
          q.push_back({min(i + r, n - 1), can});
          sum += can;
        }

        if (sum < x)
          return 0;
      }
      return 1;
    };

    for (int64 l = 0, r = accumulate(s.begin(), s.end(), 0LL) + k; l <= r;) {
      int64 mid = (l + r) / 2;
      if (test(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
