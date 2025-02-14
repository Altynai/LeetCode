using int64 = long long;

class Solution {
public:
  long long maxScore(vector<int> &a, int m) {
    int n = a.size();

    vector<int64> visited(n, 0);

    auto Test = [&](int64 target) -> bool {
      visited.assign(n, 0);
      for (int i = 0; i < n - 1; i++) {
        visited[i]++;
        int64 times = 0;
        if ((target + a[i] - 1) / a[i] > visited[i])
          times = (target + a[i] - 1) / a[i] - visited[i];
        if (times > 0) {
          if (i + 1 < n)
            visited[i + 1] += times;
          else
            visited[i - 1] += times;
          visited[i] += times;
        }
      }

      int64 times = 0;
      if ((target + a[n - 1] - 1) / a[n - 1] > visited[n - 1])
        times = (target + a[n - 1] - 1) / a[n - 1] - visited[n - 1];

      if (times > 0) {
        visited[n - 1] += times;
        visited[n - 2] += times - 1;
      }

      int64 res = 0;
      for (int i = 0; res <= m and i < n; i++)
        res += visited[i];
      return res <= m;
    };

    int64 ans = 0;
    for (int64 l = 0, r = LLONG_MAX / 2; l <= r;) {
      int64 mid = (r - l) / 2 + l;
      if (Test(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
}
