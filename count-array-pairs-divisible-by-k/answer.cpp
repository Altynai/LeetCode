class Solution {
public:
  long long countPairs(vector<int> &a, int k) {
    int n = a.size();
    if (k == 1)
      return 1LL * n * (n - 1) / 2;

    const int N = *max_element(a.begin(), a.end()) + 1;
    vector<int> cnt(N, 0);
    for (int x : a)
      cnt[x]++;
    vector<int> cc(N, 0);
    for (int i = 1; i < N; i++) {
      for (int j = i; j < N; j += i)
        cc[i] += cnt[j];
    }

    long long ans = 0;
    for (int x : a) {
      int y = k / gcd(k, x);
      ans += (y < N ? cc[y] : 0);
      if (1LL * x * x % k == 0)
        ans -= 1;
    }
    return ans / 2;
  }
};
