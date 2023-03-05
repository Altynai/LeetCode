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
} prime_factorization(1e3 + 5);

class Solution {
public:
  int findValidSplit(vector<int> &a) {
    int n = a.size();

    unordered_map<int, int> l, r;
    for (int i = 0; i < n; i++) {
      for (auto &[p, cnt] : prime_factorization.getFactors(a[i])) {
        l[p] = (l.count(p) ? min(l[p], i) : i);
        r[p] = (r.count(p) ? max(r[p], i) : i);
      }
    }

    vector<int> sum(n, 0);
    auto rangeAdd = [&](int x, int y) {
      sum[x] += 1;
      if (y + 1 < n)
        sum[y + 1] -= 1;
    };

    for (auto [p, idx] : l) {
      int idx2 = r[p];
      if (idx == idx2)
        rangeAdd(0, n - 1);
      else {
        if (idx > 0)
          rangeAdd(0, idx - 1);
        rangeAdd(idx2, n - 1);
      }
    }

    int cntp = l.size();
    for (int i = 0; i <= n - 2; i++) {
      if (i > 0)
        sum[i] += sum[i - 1];
      if (sum[i] == cntp)
        return i;
    }
    return -1;
  }
};
