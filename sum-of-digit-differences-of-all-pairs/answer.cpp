using int64 = long long;

const int N = 10;

class Solution {
public:
  long long sumDigitDifferences(vector<int> &a) {
    int n = a.size();
    int64 ans = 0;
    while (a[0] > 0) {
      vector<int> cnt(N, 0);
      for (int i = 0; i < n; i++) {
        cnt[a[i] % N]++;
        a[i] /= N;
      }
      for (int i = 0; i < N; i++) {
        if (cnt[i] > 0 and cnt[i] < n)
          ans += 1LL * cnt[i] * (n - cnt[i]);
      }
    }
    return ans / 2;
  }
};
