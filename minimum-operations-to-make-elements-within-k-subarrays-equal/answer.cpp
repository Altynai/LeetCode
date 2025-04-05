template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

using int64 = long long;

struct Medium {
  multiset<int> l, r;
  int64 lsum, rsum;

  Medium() {
    l.clear(), r.clear();
    lsum = rsum = 0;
  }

  void add(int x) {
    l.insert(x);
    lsum += x;
    balance();
  }

  void remove(int x) {
    auto it = l.find(x);
    if (it != l.end()) {
      l.erase(it);
      lsum -= x;
    } else {
      r.erase(r.find(x));
      rsum -= x;
    }
    balance();
  }

  int64 cost() {
    int p = l.size(), q = r.size();
    int64 mid = *prev(l.end());
    int64 res = mid * p - lsum;
    res += rsum - mid * q;
    return res;
  }

  void balance() {
    while (!l.empty() and !r.empty() and *prev(l.end()) > *r.begin()) {
      int x = *prev(l.end());
      int y = *r.begin();

      l.erase(prev(l.end())), lsum -= x;
      r.erase(r.begin()), rsum -= y;

      l.insert(y), lsum += y;
      r.insert(x), rsum += x;
    }

    // size: l = r or l = r + 1
    int sz = (l.size() + r.size() + 1) / 2;
    while (l.size() > r.size() and l.size() > sz) {
      int x = *prev(l.end());
      l.erase(prev(l.end())), lsum -= x;
      r.insert(x), rsum += x;
    }

    while (r.size() > l.size() and l.size() < sz) {
      int y = *r.begin();
      r.erase(r.begin()), rsum -= y;
      l.insert(y), lsum += y;
    }
  }
};

class Solution {
public:
  long long minOperations(vector<int> &a, int x, int k) {
    // cost[i]: minimal cost to equalize a[i - x + 1, ..., i]

    int n = a.size();
    vector<int64> cost(n, -1);
    Medium medium;
    for (int i = 0; i < x - 1; i++)
      medium.add(a[i]);
    for (int i = x - 1; i < n; i++) {
      medium.add(a[i]);
      cost[i] = medium.cost();
      medium.remove(a[i - (x - 1)]);
    }

    vector<vector<int64>> dp(n, vector<int64>(k + 1, LLONG_MAX));
    for (int i = 0; i < x; i++)
      dp[i][0] = 0;
    dp[x - 1][1] = cost[x - 1];

    for (int i = x; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        umin(dp[i][j], dp[i - 1][j]);
        if (j > 0 and dp[i - x][j - 1] != LLONG_MAX)
          umin(dp[i][j], dp[i - x][j - 1] + cost[i]);
      }
    }
    return dp[n - 1][k];
  }
};
