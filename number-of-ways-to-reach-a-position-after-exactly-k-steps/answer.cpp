const int N = 1001;
const int MOD = 1e9 + 7;

int C[N][N] = {0};

class Solution {
public:
  Solution() {
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++)
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
  int numberOfWays(int a, int b, int k) {
    int d = abs(a - b);
    if (k < d or (k - d) % 2 == 1)
      return 0;
    return C[k][(k - d) / 2];
  }
};
