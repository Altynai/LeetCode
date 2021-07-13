class Solution {
public:
  bool sumGame(string s) {
    int n = s.size() / 2;
    int lsum = 0, rsum = 0;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?')
        l++;
      else
        lsum += s[i] - '0';
    }
    for (int i = n; i < n * 2; i++) {
      if (s[i] == '?')
        r++;
      else
        rsum += s[i] - '0';
    }
    // alice makes the last move
    if ((l + r) % 2 == 1)
      return 1;

    int mi = min(l, r);
    l -= mi;
    r -= mi;

    if (lsum >= rsum) {
      if (r == 0)
        return l > 0 || lsum != rsum;
      // then l = 0 && lsum = rsum && r > 0
      int bob = r / 2;
      int d = abs(lsum - rsum);
      return !(d % 9 == 0 && d / 9 == bob);
    } else { // lsum < rsum
      if (l == 0)
        return r > 0 || lsum != rsum;
      // then r = 0 && lsum < rsum && l > 0
      int bob = l / 2;
      int d = abs(lsum - rsum);
      return !(d % 9 == 0 && d / 9 == bob);
    }
  }
};
