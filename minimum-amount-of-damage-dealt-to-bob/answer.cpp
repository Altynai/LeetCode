using int64 = long long;

class Solution {
public:
  long long minDamage(int power, vector<int> &d, vector<int> &h) {
    /*
    consider only i and j
    1. kill i first
    cost = d[i] * t[i] + d[j] * (t[i] + t[j]) + rest;
    2. kill j first
    cost = d[i] * (t[i] + t[j]) + d[j] * t[j] + rest;

    option 1 is better when d[j] * t[i] < d[i] * t[j]
    */
    int n = d.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
      int ti = (h[i] + power - 1) / power;
      int tj = (h[j] + power - 1) / power;
      return ti * d[j] < tj * d[i];
    });

    int64 ans = 0;
    int sum = accumulate(d.begin(), d.end(), 0);
    for (int i = 0; i < n; i++) {
      int j = p[i];
      int tj = (h[j] + power - 1) / power;
      ans += 1LL * sum * tj;
      sum -= d[j];
    }
    return ans;
  }
};
