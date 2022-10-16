const int N = 1e5 + 1;

class Solution {
public:
  vector<bool> ok;

  Solution() {
    ok = vector<bool>(N, 0);
    ok[0] = 1;

    for (int x = 1; x < N; x++) {
      int y = 0, z = x;
      while (z > 0)
        y = y * 10 + z % 10, z /= 10;
      if (x + y <= N)
        ok[x + y] = 1;
    }
  }

  bool sumOfNumberAndReverse(int n) { return ok[n]; }
};
