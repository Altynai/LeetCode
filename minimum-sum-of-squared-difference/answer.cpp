using int64 = long long;

class Solution {
public:
  int64 minSumSquareDiff(vector<int> &a, vector<int> &b, int k1, int k2) {
    int n = a.size();
    int64 m = k1 + k2;

    map<int64, int64> p;
    for (int i = 0; i < n; i++)
      p[abs(a[i] - b[i])]++;

    while (m > 0) {
      auto it = prev(p.end());
      auto [x, cnt] = *it;
      if (x == 0)
        break;

      p.erase(it);

      if (m <= cnt) {
        p[x - 1] += m;
        p[x] += cnt - m;
        m = 0;
      } else {
        // move them to the second largest
        int sec = 0;
        if (!p.empty())
          sec = prev(p.end())->first;

        int64 best = x - min(m, (x - sec) * cnt) / cnt;
        m -= (x - best) * cnt;
        p[best] += cnt;
      }
    }

    int64 ans = 0;
    for (auto [x, cnt] : p)
      ans += x * x * cnt;
    return ans;
  }
};
