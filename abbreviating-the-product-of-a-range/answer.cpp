const long long E12 = 1e12;
const long long E10 = 1e10;
const long long E5 = 1e5;

class Solution {
public:
  string abbreviateProduct(int left, int right) {
    int cnt = 0;
    long long sfx = 1;
    long double pfx = 1;
    for (int i = left; i <= right; i++) {
      sfx *= i;
      while (sfx % 10 == 0)
        sfx /= 10, cnt++;
      sfx %= E12;

      pfx *= i;
      while (pfx >= E5)
        pfx /= 10;
    }

    char buf[100];
    int n;
    if (sfx >= E10) {
      sfx %= E5;
      n = sprintf(buf, "%lld...%05lld", (long long)(pfx), sfx);
    } else
      n = sprintf(buf, "%lld", sfx);
    return string(buf, buf + n) + "e" + to_string(cnt);
  }
};
