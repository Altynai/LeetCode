#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int maximumXOR(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 30; i >= 0; i--) {
      int one = 0;
      for (int x : a)
        if (bit(x, i))
          one++;

      // 0 -> 1 is impossible
      if (one > 0)
        ans |= (1 << i);
    }
    return ans;
  }
};
