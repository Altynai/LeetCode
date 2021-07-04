using ll = long long;
using HashSet = unordered_set<ll>;

// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int longestCommonSubpath(int n, vector<vector<int>> &p) {
    vector<ll> BASE = {104491LL, 104537LL};
    vector<ll> MOD = {1000000007LL, 970592641LL};

    int l = 0, r = INT_MAX;
    for (int i = 0; i < p.size(); i++)
      umin(r, (int)p[i].size());

    int ans = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      vector<HashSet> hsOld(2, HashSet());

      for (int i = 0; i < p.size(); i++) {
        vector<HashSet> hsNew(2, HashSet());
        vector<ll> power(2, 1LL), hval(2, 0LL);

        for (int j = 0; j < p[i].size(); j++) {
          for (int k = 0; k < 2; k++)
            hval[k] = (hval[k] * BASE[k] + p[i][j]) % MOD[k];

          if (j < m) {
            for (int k = 0; k < 2; k++)
              power[k] = power[k] * BASE[k] % MOD[k];
          } else {
            for (int k = 0; k < 2; k++)
              hval[k] =
                  (MOD[k] + hval[k] - power[k] * p[i][j - m] % MOD[k]) % MOD[k];
          }

          if (j >= m - 1 && (i == 0 || (hsOld[0].count(hval[0]) &&
                                        hsOld[1].count(hval[1])))) {
            for (int k = 0; k < 2; k++)
              hsNew[k].insert(hval[k]);
          }
        }

        for (int k = 0; k < 2; k++)
          swap(hsOld[k], hsNew[k]);

        if (hsOld[0].empty() || hsOld[1].empty())
          break;
      }

      if (hsOld[0].empty() || hsOld[1].empty()) {
        r = m - 1;
      } else {
        ans = m;
        l = m + 1;
      }
    }
    return ans;
  }
};
