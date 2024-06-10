class Solution {
public:
  int numberOfChild(int n, int k) {
    int d = +1, pos = 0;
    while (k--) {
      if (pos + d < 0 or pos + d >= n)
        d *= -1;
      pos += d;
    }
    return pos;
  }
};
