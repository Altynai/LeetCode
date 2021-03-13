// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minChanges(vector<int> &nums, int k) {
    int n = nums.size();
    vector<map<int, int>> cnt(k);
    vector<int> sz(k, 0);
    for (int i = 0; i < n; i++) {
      sz[i % k]++;
      cnt[i % k][nums[i]]++;
    }

    const int m = 1 << 10;
    vector<int> dp(m);
    for (int i = 0; i < m; i++) {
      if (cnt[0].count(i))
        dp[i] = sz[0] - cnt[0][i];
      else
        dp[i] = sz[0];
    }

    for (int i = 1; i < k; i++) {
      vector<int> ndp(m, INT_MAX);
      int mn = *min_element(dp.begin(), dp.end());
      for (int j = 0; j < m; j++) {
        // choose someone in group i
        for (auto &[num, val] : cnt[i]) {
          umin(ndp[j], dp[num ^ j] + sz[i] - val);
        }
        // change all nums in group i
        umin(ndp[j], mn + sz[i]);
      }
      dp = ndp;
    }
    return dp[0];
  }
};
