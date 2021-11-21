#define MAX_DIGITS 12

class Solution {
public:
  long long kMirror(int k, int n) {
    vector<long long> tens(MAX_DIGITS, 1);
    for (int i = 1; i < MAX_DIGITS; i++)
      tens[i] = tens[i - 1] * 10;

    vector<int> buf(100);
    auto isKMirror = [&](long long a) -> bool {
      int m = 0;
      while (a > 0) {
        buf[m++] = a % k;
        a /= k;
      }
      for (int i = 0; i < m / 2; i++)
        if (buf[i] != buf[m - 1 - i])
          return 0;
      return 1;
    };

    set<long long> seen;
    vector<int> number(MAX_DIGITS, 0);

    function<void(int, int)> dfs = [&](int digits, int i) {
      int j = digits - 1 - i;
      for (int d = (i == 0 ? 1 : 0); d <= 9; d++) {
        number[i] = number[j] = d;

        long long x = 0;
        for (int p = 0; p < digits; p++)
          x += tens[p] * number[p];

        if (isKMirror(x) && seen.size() < n)
          seen.insert(x);

        if (i + 1 <= j - 1)
          dfs(digits, i + 1);
      }
      number[i] = number[j] = 0;
    };

    for (int digits = 1; seen.size() < n && digits <= MAX_DIGITS; digits++)
      dfs(digits, 0);

    long long ans = 0;
    for (long long x : seen) {
      if (n--)
        ans += x;
      else
        break;
    }
    return ans;
  }
};
