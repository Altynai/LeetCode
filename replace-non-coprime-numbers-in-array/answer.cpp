class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int> &a) {
    vector<int> s;
    int m = 0;
    for (int x : a) {
      if (m == s.size())
        s.push_back(x), m++;
      else
        s[m++] = x;

      while (m >= 2) {
        int g = gcd(s[m - 1], s[m - 2]);
        if (g == 1)
          break;
        s[m - 2] = 1LL * s[m - 1] * s[m - 2] / g;
        m--;
      }
    }
    s.resize(m);
    return s;
  }
};
