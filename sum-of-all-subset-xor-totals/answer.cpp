class Solution {
public:
  int subsetXORSum(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
      int p = 0;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
          p ^= a[i];
      }
      ans += p;
    }
    return ans;
  }
};
