#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int countMaxOrSubsets(vector<int> &a) {
    int n = a.size();
    int best = 0, cnt = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
      int val = 0;
      for (int i = 0; i < n; i++) {
        if (bit(mask, i))
          val |= a[i];
      }
      if (val > best) {
        best = val;
        cnt = 1;
      } else if (val == best)
        cnt++;
    }
    return cnt;
  }
};
