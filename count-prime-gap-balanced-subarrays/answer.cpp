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
} pf(5e4 + 1);

class Solution {
public:
  int primeSubarray(vector<int> &a, int k) {
    const auto &is_prime = pf.p;
    int n = a.size();
    multiset<int> primes;

    int pos0 = -1, pos1 = -1; // recent 2 primes
    auto isBad = [&]() -> bool {
      return primes.size() > 0 and *primes.rbegin() - *primes.begin() > k;
    };

    auto Add = [&](int j) {
      if (is_prime[a[j]]) {
        pos0 = pos1;
        pos1 = j;
        primes.insert(a[j]);
      }
    };

    auto Remove = [&](int j) {
      if (is_prime[a[j]])
        primes.erase(primes.find(a[j]));
    };

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      Add(i);
      while (isBad())
        Remove(j++);
      if (!isBad())
        ans += pos0 - j + 1;
    }
    return ans;
  }
};
