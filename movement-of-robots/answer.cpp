using int64 = long long;

const int MOD = 1e9 + 7;

class Solution {
public:
  int sumDistance(vector<int> &a, string s, int d) {
    int n = a.size();
    vector<int64> b(n);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L')
        b[i] = 1LL * a[i] - d;
      else
        b[i] = 1LL * a[i] + d;
    }
    sort(b.begin(), b.end());

    int64 ans = 0, sum = b[0];
    for (int i = 1; i < n; i++) {
      ans += 1LL * b[i] * i - sum;
      ans %= MOD;
      sum += b[i];
      sum %= MOD;
    }
    return ans;
  }
};
