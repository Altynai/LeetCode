using int64 = long long;

class Solution {
public:
  vector<int> permute(int n, long long k) {
    vector<int> ans(n, -1);
    vector<set<int>> s(2);
    for (int i = 1; i <= n; i++)
      s[i & 1].insert(i);

    auto IsFactorialBad = [&](int m) -> bool {
      int64 res = 1;
      for (int i = 1; i <= m; i++) {
        res *= i;
        if (res > k)
          return 1;
      }
      return 0;
    };

    auto Factorial = [&](int m) -> int64 {
      int64 res = 1;
      for (int i = 1; i <= m; i++)
        res *= i;
      return res;
    };

    auto CountWays = [&](int parity) -> int64 {
      vector<int> cnt(2);
      for (int i = 0; i < 2; i++)
        cnt[i] = s[i].size();
      cnt[parity]--;

      if (IsFactorialBad(cnt[0]) or IsFactorialBad(cnt[1]))
        return -1;

      int64 p = Factorial(cnt[0]);
      int64 q = Factorial(cnt[1]);
      // p * q <= k
      if (p <= k / q)
        return p * q;
      else
        return -1;
    };

    if (n & 1) {
      // odd, even, odd, ..., odd
      // first element must be odd
      for (int i = 0; i < n; i++) {
        int parity = (i & 1) ^ 1;
        int64 ways = CountWays(parity);
        if (ways == -1) {
          ans[i] = *s[parity].begin();
          s[parity].erase(s[parity].begin());
        } else {
          int id = (k % ways == 0 ? k / ways : k / ways + 1);
          if (id > s[parity].size())
            return {};

          auto it = s[parity].begin();
          for (int j = 2; j <= id; j++)
            it++;
          assert(it != s[parity].end());

          ans[i] = *it;
          s[parity].erase(it);
          k -= ways * (id - 1);
        }
      }
    } else {
      // first element can be odd or even
      int parity = 1;
      int64 ways = CountWays(1);
      if (ways == -1) {
        ans[0] = 1;
        s[1].erase(1);
      } else {
        int id = (k % ways == 0 ? k / ways : k / ways + 1);
        if (id > n)
          return {};

        parity = (id & 1);
        ans[0] = id;
        s[parity].erase(id);
        k -= ways * (id - 1);
      }

      for (int i = 1; i < n; i++) {
        parity ^= 1;
        int64 ways = CountWays(parity);
        if (ways == -1) {
          ans[i] = *s[parity].begin();
          s[parity].erase(s[parity].begin());
        } else {
          int id = (k % ways == 0 ? k / ways : k / ways + 1);
          if (id > s[parity].size())
            return {};

          auto it = s[parity].begin();
          for (int j = 2; j <= id; j++)
            it++;
          assert(it != s[parity].end());

          ans[i] = *it;
          s[parity].erase(it);
          k -= ways * (id - 1);
        }
      }
    }
    return ans;
  }
};
