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
} pf(1e4 + 3);

const int N = 1e4;

class Solution {
public:
  int minOperations(int n, int m) {
    const vector<bool> is_prime = pf.p;
    if (is_prime[n] or is_prime[m])
      return -1;

    vector<int> dis(N, INT_MAX);

    using State = pair<int, int>;
    priority_queue<State, vector<State>, greater<State>> q;
    dis[n] = n;
    q.push({n, n});

    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      // skip invalid node
      if (dis[u] != d)
        continue;

      string s = to_string(u);
      int len = s.size();
      for (int i = 0; i < len; i++) {
        vector<string> candidates;
        if (s[i] < '9') {
          s[i]++;
          candidates.push_back(s);
          s[i]--;
        }
        if (s[i] > '1' or i > 0) {
          s[i]--;
          candidates.push_back(s);
          s[i]++;
        }
        for (string t : candidates) {
          int v = stoi(t);
          if (!is_prime[v] and d + v < dis[v]) {
            dis[v] = d + v;
            q.push({dis[v], v});
          }
        }
      }
    }
    return dis[m] == INT_MAX ? -1 : dis[m];
  }
};
