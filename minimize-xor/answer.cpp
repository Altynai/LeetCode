#define bit(n, i) (((n) >> (i)) & 1)
#define bitCount(n) __builtin_popcountll((n))

const int N = 30;

class Solution {
public:
  int minimizeXor(int a, int b) {
    int n = bitCount(b);
    vector<bool> used(N, 0);

    int ans = 0;
    for (int i = N - 1; n > 0 and i >= 0; i--) {
      if (bit(a, i)) {
        n--;
        ans |= (1 << i);
        used[i] = 1;
      }
    }
    for (int i = 0; n > 0 and i < N; i++) {
      if (!used[i]) {
        n--;
        ans |= (1 << i);
      }
    }
    return ans;
  }
};
