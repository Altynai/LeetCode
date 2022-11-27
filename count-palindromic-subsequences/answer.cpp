const int MOD = 1e9 + 7;

class Solution {
public:
  int countPalindromes(string s) {
    int n = s.size();

    vector<int> cnt1(10, 0);
    vector<vector<int>> cnt2(n + 1, vector<int>(100, 0));

    vector<int> bcnt1(10, 0);
    vector<vector<int>> bcnt2(n + 2, vector<int>(100, 0));

    for (int i = 1; i <= n; i++) {

      for (int j = 0; j < 100; j++)
        cnt2[i][j] = cnt2[i - 1][j];

      int k = s[i - 1] - '0';
      for (int j = 0; j < 10; j++)
        cnt2[i][j * 10 + k] += cnt1[j];
      cnt1[k]++;
    }

    for (int i = n; i >= 1; i--) {
      for (int j = 0; j < 100; j++)
        bcnt2[i][j] = bcnt2[i + 1][j];

      int k = s[i - 1] - '0';
      for (int j = 0; j < 10; j++)
        bcnt2[i][k * 10 + j] += bcnt1[j];
      bcnt1[k]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 100; j++) {
        int k = (j % 10) * 10 + (j / 10);
        int p = 1LL * cnt2[i - 1][j] * bcnt2[i + 1][k] % MOD;
        ans = (ans + p) % MOD;
      }
    }
    return ans;
  }
};
