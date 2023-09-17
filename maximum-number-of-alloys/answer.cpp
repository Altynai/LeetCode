using int64 = long long;

class Solution {
public:
  int maxNumberOfAlloys(int n, int k, int budget,
                        vector<vector<int>> &composition, vector<int> &stock,
                        vector<int> &cost) {
    int ans = 0;
    for (auto &c : composition) {
      int best = -1;
      for (int l = 0, r = 1e9; l <= r;) {
        int mid = (l + r) / 2;
        int64 money = budget;
        for (int j = 0; money >= 0 and j < n; j++) {
          int64 need = 1LL * c[j] * mid - stock[j];
          if (need < 0)
            continue;
          money -= need * cost[j];
        }
        if (money >= 0)
          best = mid, l = mid + 1;
        else
          r = mid - 1;
      }
      if (best != -1)
        ans = max(ans, best);
    }
    return ans;
  }
};
