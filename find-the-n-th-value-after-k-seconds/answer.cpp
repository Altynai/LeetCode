const int MOD = 1e9 + 7;

class Solution {
public:
  int valueAfterKSeconds(int n, int k) {
    vector<int> a(n, 1);
    while (k--) {
      for (int i = 1; i < n; i++)
        a[i] = (a[i] + a[i - 1]) % MOD;
    }
    return a[n - 1];
  }
};
