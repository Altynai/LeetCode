#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

class Solution {
public:
  int maxProduct(string s) {
    int n = s.size();
    vector<bool> p(1 << n, 0);
    vector<int> bc(1 << n, 0);
    for (int i = 1; i < (1 << n); i++) {
      bc[i] = bitCount(i);
      vector<int> indices;
      for (int j = 0; j < n; j++) {
        if (bit(i, j))
          indices.push_back(j);
      }
      int m = indices.size();
      p[i] = 1;
      for (int j = 0, k = m - 1; j <= k; j++, k--) {
        if (s[indices[j]] != s[indices[k]]) {
          p[i] = 0;
          break;
        }
      }
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
      if (!p[i])
        continue;
      int mask = i ^ ((1 << n) - 1);
      for (int j = mask; j > 0; j = (j - 1) & mask) {
        if (p[j])
          ans = max(ans, bc[i] * bc[j]);
      }
    }
    return ans;
  }
};
