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
} prime_factorization(1010);

class Solution {
public:
  bool primeSubOperation(vector<int> &a) {
    vector<int> p = prime_factorization.primes;

    int n = a.size();
    for (int i = 0; i < n; i++) {
      if (i > 0 and a[i] <= a[i - 1])
        return 0;

      int d = (i == 0 ? a[i] : a[i] - a[i - 1]);
      if (d >= 3) {
        int x = lower_bound(p.begin(), p.end(), d) - p.begin();
        if (x > 0)
          a[i] -= p[x - 1];
      }
    }
    return 1;
  }
};
