template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maximumTotalDamage(vector<int> &p) {
    unordered_map<int, int> freq;
    for (int x : p)
      freq[x]++;

    vector<int> v;
    for (auto [k, _] : freq)
      v.push_back(k);
    sort(v.begin(), v.end());
    int n = v.size();

    vector<int64> dp(n, 0);
    dp[0] = 1LL * v[0] * freq[v[0]];
    for (int i = 1; i < n; i++) {
      int64 val = 1LL * v[i] * freq[v[i]];
      // edge case: only choose itself
      umax(dp[i], val);

      // can not choose v[i] - 1, v[i] - 2
      int j = i - 1;
      while (j >= 0 and v[j] >= v[i] - 2)
        j--;
      if (j >= 0)
        umax(dp[i], dp[j] + val);

      umax(dp[i], dp[i - 1]);
    }

    return dp[n - 1];
  }
};
