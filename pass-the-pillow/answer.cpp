class Solution {
public:
  int passThePillow(int n, int time) {
    int d = 1, p = 1;
    while (time--) {
      if (p == n)
        d = -1;
      else if (p == 1)
        d = 1;
      p += d;
    }
    return p;
  }
};
