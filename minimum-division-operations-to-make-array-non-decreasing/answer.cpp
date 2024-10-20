struct PrimeFactorization {

  // primes.size() <= sqrt(n)
  vector<int> primes;
  vector<bool> p;

  PrimeFactorization(int n) {
    p.resize(n);
    p.assign(n, true);

    p[0] = p[1] = 0;
    for (int i = 4; i < n; i += 2)
      p[i] = 0;
    for (int i = 3; i * i < n; i += 2) {
      if (!p[i])
        continue;
      for (int j = i * i; j < n; j += i)
        p[j] = 0;
    }

    primes = {2};
    for (int i = 3; i < n; i += 2)
      if (p[i])
        primes.push_back(i);
  }

  vector<pair<int, int>> getFactors(int n) {
    vector<pair<int, int>> ans;
    for (int i = 0; n > 1 && i < (int)primes.size(); i++) {
      int cnt = 0;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      if (cnt)
        ans.emplace_back(primes[i], cnt);
    }
    if (n > 1)
      ans.emplace_back(n, 1);
    return ans;
  }
} pf(1005);

class Solution {
private:
  int op(int x) {
    if (x == 1)
      return 1;
    auto facts = pf.getFactors(x);
    return facts[0].first;
  }

public:
  int minOperations(vector<int> &a) {
    int n = a.size(), ans = INT_MAX;
    for (int w = 0; w < 2; w++) {
      vector<int> b = a;
      int cnt = 0;
      bool ok = 1;
      for (int i = n - 2; ok and i >= 0; i--) {
        if (b[i] <= b[i + 1])
          continue;
        int val = op(b[i]);
        if (val == b[i])
          ok = 0;
        else
          b[i] = val, cnt++;
        if (b[i] > b[i + 1])
          ok = 0;
      }
      if (ok)
        ans = min(ans, cnt);

      a.back() = op(a.back());
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
