#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int sumIndicesWithKSetBits(vector<int> &a, int k) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
      if (bitCount(i) == k)
        ans += a[i];
    }
    return ans;
  }
};
