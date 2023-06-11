template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long minCost(vector<int> &a, int x) {
    int n = a.size();
    // shift cost
    vector<vector<int64>> sc(n, vector<int64>(n, 0));
    for (int i = 0; i < n; i++) {
      sc[i][0] = a[i];
      for (int j = 1; j < n; j++) {
        int k = (i - j + n) % n;
        sc[i][j] = min(sc[i][j - 1], 1LL * a[k]);
      }
    }

    int64 ans = LLONG_MAX;
    for (int j = 0; j < n; j++) {
      int64 cost = 1LL * x * j;
      for (int i = 0; i < n; i++)
        cost += sc[i][j];
      umin(ans, cost);
    }
    return ans;
  }
};
