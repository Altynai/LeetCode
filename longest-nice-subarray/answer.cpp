#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

const int N = 30;

class Solution {
public:
  int longestNiceSubarray(vector<int> &a) {
    int n = a.size();
    vector<int> cnt(N, 0);

    auto valid = [&]() -> bool {
      for (int i = 0; i < N; i++) {
        if (cnt[i] >= 2)
          return 0;
      }
      return 1;
    };

    int ans = 0;
    for (int j = 0, i = 0; j < n; j++) {
      for (int k = 0; k < N; k++)
        if (bit(a[j], k))
          cnt[k]++;

      while (!valid()) {
        for (int k = 0; k < N; k++)
          if (bit(a[i], k))
            cnt[k]--;
        i++;
      }

      ans = max(ans, j - i + 1);
    }
    return ans;
  }
};
