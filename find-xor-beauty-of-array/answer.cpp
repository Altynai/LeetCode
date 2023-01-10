using int64 = long long;

#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int xorBeauty(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < 30; i++) {
      int64 one = 0;
      for (int j = 1; j <= n; j++) {
        if (bit(a[j - 1], i))
          one++;
      }

      int64 y = 0;
      for (int j = 1; j <= n; j++) {
        if (bit(a[j - 1], i)) {
          y += n * one;
        } else {
          y += one * one;
        }
      }
      if (y & 1)
        ans |= (1 << i);
    }
    return ans;
  }
};
