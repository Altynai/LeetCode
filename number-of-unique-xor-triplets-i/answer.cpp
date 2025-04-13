#define bit(n, i) (((n) >> (i)) & 1)

class Solution {
public:
  int uniqueXorTriplets(vector<int> &a) {
    int n = a.size();
    if (n <= 2)
      return n;

    // find max possible value
    int msb = 0;
    for (int i = 0; i < 20; i++) {
      for (int x : a) {
        if (bit(x, i))
          msb = i;
      }
    }
    return 1 << (msb + 1);
  }
};
