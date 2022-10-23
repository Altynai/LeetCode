using int64 = long long;

class Solution {
public:
  int64 minCost(vector<int> &a, vector<int> &cost) {
    int n = a.size();
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
      b[i] = {a[i], cost[i]};

    sort(b.begin(), b.end());

    vector<int64> pfx(n, 0);
    int64 added = b[0].second;
    for (int i = 1; i < n; i++) {
      pfx[i] = pfx[i - 1] + added * (b[i].first - b[i - 1].first);
      added += b[i].second;
    }

    vector<int64> sfx(n, 0);
    added = b[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
      sfx[i] = sfx[i + 1] + added * (b[i + 1].first - b[i].first);
      added += b[i].second;
    }

    int64 ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
      ans = min(ans, pfx[i] + sfx[i]);
    return ans;
  }
};
