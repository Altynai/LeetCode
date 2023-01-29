using int64 = long long;

class Solution {
public:
  int64 putMarbles(vector<int> &w, int k) {
    // merge [i ... j] [j + 1 ... k]
    // we need to merge n - k times

    // old score = w[i] + w[j] + w[j + 1] + w[k]
    // new score = w[i] + w[k]
    // so we lose w[j] + w[j + 1] as delta

    int n = w.size();
    vector<int64> d;
    for (int i = 1; i < n; i++)
      d.push_back(w[i - 1] + w[i]);

    sort(d.begin(), d.end());
    int m = d.size();
    int64 ma = 0, mi = 0;
    for (int i = 0; i < n - k; i++) {
      ma += d[m - 1 - i];
      mi += d[i];
    }
    return abs(ma - mi);
  }
};
