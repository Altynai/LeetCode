using int64 = long long;

const int N = 10;

class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    vector<int64> tens(n, 1);
    for (int i = 1; i < n; i++)
      tens[i] = tens[i - 1] * 10;

    vector<int64> f(n + 1, 1);
    for (int i = 1; i <= n; i++)
      f[i] = f[i - 1] * i;

    unordered_set<string> seen;
    int m = (n + 1) / 2;
    int nines = stoi(string(m, '9'));

    auto IsGood = [&](int x) -> bool {
      if (x % 10 == 0)
        return false;

      int64 res = 0;
      for (int i = 0; i < m; i++) {
        int digit = x % 10;
        x /= 10;
        int64 sum = (tens[i] + tens[n - 1 - i]) * digit;
        if (n % 2 == 1 and i == n / 2)
          sum /= 2;
        res += sum % k;
        res %= k;
      }
      return res == 0;
    };

    auto GenerateString = [&](int x) -> string {
      string res(n, '0');
      for (int i = 0; i < m; i++) {
        int digit = x % 10;
        x /= 10;
        res[i] = res[n - 1 - i] = ('0' + digit);
      }
      return res;
    };

    auto Count = [&](const string &s) -> int64 {
      vector<int> cnt(N, 0);
      for (char ch : s)
        cnt[ch - '0']++;

      int64 res = 1;
      int pos;
      if (cnt[0] > 0) {
        pos = n - 1;
        for (int num = cnt[0]; num > 0; num--) {
          res *= pos;
          pos--;
        }
      }
      pos = n - cnt[0];
      for (int num = n - cnt[0]; num > 0; num--) {
        res *= pos;
        pos--;
      }

      for (int i = 0; i < N; i++) {
        if (cnt[i] > 0)
          res /= f[cnt[i]];
      }
      return res;
    };

    int64 ans = 0;
    for (int i = 1; i <= nines; i++) {
      if (IsGood(i)) {
        string s = GenerateString(i);
        sort(s.begin(), s.end());
        if (seen.count(s) == 0) {
          ans += Count(s);
          seen.insert(s);
        }
      }
    }
    return ans;
  }
};
