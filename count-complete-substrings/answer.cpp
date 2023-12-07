const int N = 26;

class Solution {
public:
  int countCompleteSubstrings(string s, int k) {
    int n = s.size();

    vector<int> sum(n + 1, 0);
    for (int i = 2; i <= n; i++) {
      sum[i] = sum[i - 1] + int(abs(s[i - 1] - s[i - 2]) <= 2);
    }

    vector<vector<int>> cnt(n + 1, vector<int>(N, 0));
    for (int i = 1; i <= n; i++) {
      cnt[i] = cnt[i - 1];
      cnt[i][s[i - 1] - 'a']++;
    }

    auto isGood = [&](int l, int r) -> bool {
      for (int j = 0; j < N; j++) {
        int x = cnt[r][j] - cnt[l - 1][j];
        if (x != 0 and x != k)
          return 0;
      }
      return 1;
    };

    int ans = 0;
    for (int cnt = 1; cnt <= N; cnt++) {
      int len = k * cnt;
      if (len > n)
        break;

      for (int i = len; i <= n; i++) {
        if (sum[i] - sum[i - len + 1] == len - 1 and isGood(i - len + 1, i))
          ans++;
      }
    }
    return ans;
  }
};
