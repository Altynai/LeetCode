class Solution {
public:
  int colorTheGrid(int n, int m) {

    auto checkColor = [&](int c) -> bool {
      for (int i = 0, pre = -1; i < n; i++) {
        if (pre == c % 3)
          return 0;
        pre = c % 3;
        c /= 3;
      }
      return 1;
    };

    auto checkColors = [&](int c1, int c2) -> bool {
      for (int i = 0; i < n; i++) {
        if (c1 % 3 == c2 % 3)
          return 0;
        c1 /= 3;
        c2 /= 3;
      }
      return 1;
    };

    int mask = 1;
    for (int i = 0; i < n; i++)
      mask *= 3;

    const int MOD = 1e9 + 7;
    vector<int> dp(mask, 0);
    for (int i = 0; i < mask; i++) {
      if (checkColor(i))
        dp[i] = 1;
    }

    vector<pair<int, int>> transfer;
    for (int j = 0; j < mask; j++) {
      if (!checkColor(j))
        continue;
      for (int k = 0; k < mask; k++) {
        if (checkColor(k) && checkColors(j, k)) {
          transfer.emplace_back(j, k);
        }
      }
    }

    for (int i = 1; i < m; i++) {
      vector<int> ndp(mask, 0);
      for (auto [j, k] : transfer) {
        ndp[k] += dp[j];
        ndp[k] %= MOD;
      }
      dp = ndp;
    }

    int ans = 0;
    for (int i = 0; i < mask; i++) {
      ans += dp[i];
      ans %= MOD;
    }
    return ans;
  }
};
