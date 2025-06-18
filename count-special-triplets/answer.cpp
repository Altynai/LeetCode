const int MOD = 1e9 + 7;

class Solution {
public:
  int specialTriplets(vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> x, y;
    x[a[0]]++;
    for (int i = 2; i < n; i++)
      y[a[i]]++;

    int ans = 0;
    for (int j = 1; j < n - 1; j++) {
      ans += 1LL * x[a[j] * 2] * y[a[j] * 2] % MOD;
      ans %= MOD;
      x[a[j]]++;
      y[a[j + 1]]--;
    }
    return ans;
  }
};
