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
} prime_factorization(1e6 + 5);

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    const vector<int> &p = prime_factorization.primes;

    int n = p.size();
    int L = -1, R = -1;
    for (int i = 1; i < n; i++) {
      int x = p[i] - p[i - 1];
      if (left <= p[i - 1] and p[i] <= right) {
        if (L == -1 or x < (R - L))
          L = p[i - 1], R = p[i];
      }
    }
    return {L, R};
  }
};
