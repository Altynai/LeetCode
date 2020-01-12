class Solution {
  public int minFlips(int a, int b, int c) {
    int ans = 0;
    for (int i = 0; i < 31; i++) {
      int ae = a % 2, be = b % 2, ce = c % 2;
      a >>= 1;
      b >>= 1;
      c >>= 1;
      if ((ae | be) != ce) ans += (ce == 0) ? ae + be : 1;
    }
    return ans;
  }
}

