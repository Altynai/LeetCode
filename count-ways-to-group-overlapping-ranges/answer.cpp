const int MOD = 1e9 + 7;

class Solution {
public:
  int countWays(vector<vector<int>> &a) {
    int n = a.size();
    sort(a.begin(), a.end(), [](auto &lh, auto &rh) { return lh[0] < rh[0]; });

    int ans = 1;
    int l = a[0][0], r = a[0][1];
    for (int i = 1; i < n; i++) {
      if (a[i][0] > r) {
        ans = ans * 2 % MOD;
        l = a[i][0], r = a[i][1];
      } else {
        r = max(r, a[i][1]);
      }
    }
    ans = ans * 2 % MOD;
    return ans;
  }
};
