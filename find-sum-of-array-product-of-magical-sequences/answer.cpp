#define bitCount(n) __builtin_popcountll((n))

const int MOD = 1e9 + 7;

// NOTE: good performance with pre-calculation
template <class T> struct Comb {
  static const int N = 51;
  static const int M = 51;

  T C[N][M];

  void init(int n, int m) {
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= m; j++) {
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        C[i][j] %= MOD;
      }
    }
  }

  T choose(int n, int r) {
    if (n < r)
      return 0;
    if (r == 0)
      return 1;
    return C[n][r];
  }
};

class Solution {
private:
  Comb<int> comb;

  // dp[i][chosen][bits][carry]
  // we have picked `chosen` numbers for seq from `0 ~ i`
  // and `bits` has been set to 1 and we have a `carry` for the next
  int dp[51][31][31][31];

  void init(int m, int k, int n) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        for (int x = 0; x <= k; x++) {
          for (int y = 0; y <= m; y++) {
            dp[i][j][x][y] = -1;
          }
        }
      }
    }
  }

public:
  int magicalSum(int m, int k, vector<int> &a) {
    int n = a.size();

    comb.init(m, m);
    init(m, k, n);

    function<int(int, int, int, int)> dfs = [&](int pos, int chosen, int bits,
                                                int carry) -> int {
      if (chosen > m or bits > k)
        return 0;
      if (pos == n) {
        if (chosen == m and bits + bitCount(carry) == k)
          return 1;
        else
          return 0;
      }

      int &res = dp[pos][chosen][bits][carry];
      if (res != -1)
        return res;

      // skip current position
      res = dfs(pos + 1, chosen, bits + (carry % 2), carry >> 1);

      // choose some
      int mul = 1;
      for (int i = 1; i <= m - chosen; i++) {
        mul = 1LL * mul * a[pos] % MOD;
        int cb = comb.choose(m - chosen, i);
        int carry2 = carry + i;
        int ways = dfs(pos + 1, chosen + i, bits + (carry2 % 2), carry2 >> 1);
        res += 1LL * mul * cb % MOD * ways % MOD;
        res %= MOD;
      }
      return res;
    };
    return dfs(0, 0, 0, 0);
  }
};
