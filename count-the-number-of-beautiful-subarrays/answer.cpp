#define bit(n, i) (((n) >> (i)) & 1)

using int64 = long long;

const int N = 20;

class Solution {
public:
  long long beautifulSubarrays(vector<int> &a) {
    int n = a.size();
    int mask = 0;

    unordered_map<int, int> cnt;
    cnt[0] = 1;

    int64 ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < N; j++)
        mask ^= (a[i - 1] & (1 << j));
      ans += cnt[mask]++;
    }
    return ans;
  }
};
