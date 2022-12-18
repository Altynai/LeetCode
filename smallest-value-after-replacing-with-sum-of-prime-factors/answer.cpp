struct Prime {
  // primes.size() <= sqrt(n)
  vector<int> primes;
  vector<bool> p;

  Prime(int n) {
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

  int sum(int n) {
    int ans = 0;
    for (int i = 0; n > 1 && i < (int)primes.size(); i++) {
      while (n % primes[i] == 0) {
        n /= primes[i];
        ans += primes[i];
      }
    }
    if (n > 1)
      ans += n;
    return ans;
  }
} prime(1e5 + 3);

class Solution {
public:
  int smallestValue(int n) {
    while (true) {
      int x = prime.sum(n);
      if (x == n)
        break;
      n = x;
    }
    return n;
  }
};
