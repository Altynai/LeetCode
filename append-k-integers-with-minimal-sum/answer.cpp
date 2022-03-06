class Solution {
public:
  long long minimalKSum(vector<int> &a, int k) {
    auto sum = [&](int x, int n) -> long long {
      return 1LL * (x + x + n - 1) * n / 2;
    };

    sort(a.begin(), a.end());
    int l = 0, r, n = a.size();
    long long ans = 0;
    for (int i = 0; k >= 0 and i < n; i++) {
      r = a[i];
      if (r >= l + 2) {
        int m = min(k, r - l - 1);
        ans += sum(l + 1, m);
        k -= m;
      }
      l = a[i];
    }
    if (k)
      ans += sum(l + 1, k);
    return ans;
  }
};
