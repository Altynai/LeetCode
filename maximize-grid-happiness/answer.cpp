// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
// =====================================================================================================================

vector<int> cal(int val) {
  vector<int> ret(5, 0);
  for (int i = 0; i < 5; i++) {
    ret[i] = val % 3;
    val /= 3;
  }
  return ret;
}

int dp[6][243][7][7];

class Solution {
public:
  int getMaxGridHappiness(int n, int m, int introvertsCount,
                          int extrovertsCount) {
    int state = pow(3, m);

    for (int i = 0; i <= n; i++) {
      for (int mask1 = 0; mask1 < state; mask1++) {
        for (int j = 0; j <= introvertsCount; j++) {
          for (int k = 0; k <= extrovertsCount; k++) {
            dp[i][mask1][j][k] = INT_MIN;
          }
        }
      }
    }

    dp[0][0][0][0] = 0;

    vector<int> s[state];
    vector<int> cnt1(state, 0);
    vector<int> cnt2(state, 0);
    for (int mask = 0; mask < state; mask++) {
      s[mask] = cal(mask);
      cnt1[mask] = count(s[mask].begin(), s[mask].end(), 1);
      cnt2[mask] = count(s[mask].begin(), s[mask].end(), 2);
    }

    // pre compute transition value
    int add[state][state];
    memset(add, 0, sizeof(add));

    // state of previous row
    for (int mask1 = 0; mask1 < state; mask1++) {
      vector<int> &s1 = s[mask1];

      // state of current row
      for (int mask2 = 0; mask2 < state; mask2++) {
        vector<int> &s2 = s[mask2];

        int got = 0;
        for (int x = 0; x < m; x++) {
          if (s2[x] == 1) {
            got += 120;
            if (x && s2[x - 1])
              got -= 30;
            if (x + 1 < m && s2[x + 1])
              got -= 30;

            if (s1[x] == 1) {
              got -= 30;
              got -= 30;
            } else if (s1[x] == 2) {
              got -= 30;
              got += 20;
            }
          } else if (s2[x] == 2) {
            got += 40;
            if (x && s2[x - 1])
              got += 20;
            if (x + 1 < m && s2[x + 1])
              got += 20;

            if (s1[x] == 1) {
              got += 20;
              got -= 30;
            } else if (s1[x] == 2) {
              got += 20;
              got += 20;
            }
          }
        }
        add[mask1][mask2] = got;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int mask1 = 0; mask1 < state; mask1++) {

        for (int j = 0; j <= introvertsCount; j++) {
          for (int k = 0; k <= extrovertsCount; k++) {
            if (dp[i - 1][mask1][j][k] == INT_MIN)
              continue;

            for (int mask2 = 0; mask2 < state; mask2++) {

              int nj = j + cnt1[mask2];
              int nk = k + cnt2[mask2];
              if (nj > introvertsCount || nk > extrovertsCount)
                continue;

              umax(dp[i][mask2][nj][nk],
                   dp[i - 1][mask1][j][k] + add[mask1][mask2]);
              umax(ans, dp[i][mask2][nj][nk]);
            }
          }
        }
      }
    }
    return ans;
  }
};
