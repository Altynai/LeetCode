const int MOD = 1e9 + 7;

inline int normal(int x) { return (x + MOD) % MOD; }

inline void add(int &x, int y) { x = (x + normal(y)) % MOD; }

class Solution {
public:
  int countSubMultisets(vector<int> &a, int l, int r) {
    int n = a.size();
    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    vector<int> dp(r + 1, 0);
    dp[0] = freq[0] + 1;

    for (auto [val, cnt] : freq) {
      if (val == 0)
        continue;

      vector<int> pre = dp;
      for (int i = val; i <= r; i++)
        add(pre[i], pre[i - val]);
      for (int i = r; i >= 0; i--) {
        // dp[i] = dp[i] + dp[i - val] + dp[i - 2 * val] + ...
        if (i >= val * cnt + val)
          dp[i] = normal(pre[i] - pre[i - val * cnt - val]);
        else
          dp[i] = pre[i];
      }
    }

    int res = 0;
    for (int i = l; i <= r; i++)
      add(res, dp[i]);
    return res;
  }
};
