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
} prime_factorization(3163); // sqrt(1e7)

const int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int mostFrequentPrime(vector<vector<int>> &mat) {
    unordered_map<int, int> freq;
    auto Count = [&](int x) {
      if (x <= 10)
        return;

      for (int prime : prime_factorization.primes) {
        if (prime >= x)
          break;
        if (x % prime == 0)
          return;
      }
      freq[x]++;
    };

    int n = mat.size(), m = mat[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 8; k++) {
          int val = 0, pi = i, pj = j;
          while (inside(n, m, pi, pj)) {
            val = val * 10 + mat[pi][pj];
            Count(val);
            pi += dx[k], pj += dy[k];
          }
        }
      }
    }

    int best = -1, ans = -1;
    for (auto [k, v] : freq) {
      if (v > best or (v == best and k > ans))
        ans = k, best = v;
    }
    return ans;
  }
};
