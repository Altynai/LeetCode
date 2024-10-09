using int64 = long long;

class Solution {
public:
  vector<int> gcdValues(vector<int> &a, vector<long long> &queries) {
    // how to count number of pairs of gcd(a[i], a[j]) = g? 1 <= g <= max(a)
    // a[i], a[j] must one of g, 2g, 3g, ...., ng

    // so if mul = cnt[g] + cnt[2g] + ... + cnt[ng]
    // pairs: num[g] = mul * (mul - 1) / 2
    // but it may include gcd = 2g (or 3g, .... , ng)
    // hence we need to exclude them
    // num[g] = total - num[2g] - num[3g] ...

    int N = *max_element(a.begin(), a.end());
    vector<int> cnt(N + 1, 0);
    for (int x : a)
      cnt[x]++;

    vector<int64> num(N + 1, 0);
    for (int g = N; g >= 1; g--) {
      int64 mul = 0;
      for (int i = g; i <= N; i += g)
        mul += cnt[i];
      num[g] = mul * (mul - 1) / 2;
      for (int i = g * 2; i <= N; i += g)
        num[g] -= num[i];
    }

    vector<int64> psum(N + 1, 0);
    for (int i = 1; i <= N; i++)
      psum[i] = psum[i - 1] + num[i];

    int m = queries.size();
    vector<int> ans(m, -1);
    for (int i = 0; i < m; i++) {
      int64 q = queries[i] + 1;
      for (int l = 1, r = N; l <= r;) {
        int mid = (l + r) / 2;
        if (psum[mid] >= q)
          r = mid - 1, ans[i] = mid;
        else
          l = mid + 1;
      }
    }
    return ans;
  }
};
