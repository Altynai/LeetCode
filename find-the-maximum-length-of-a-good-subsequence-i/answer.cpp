template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

struct Map {
  unordered_map<int, int> freq;
  multiset<pair<int, int>> vals;

  Map() {}

  void Add(int key, int val) {
    auto it = freq.find(key);
    if (it != freq.end()) {
      vals.erase(vals.find({it->second, key}));
      freq.erase(it);
    }

    freq[key] = val;
    vals.insert({val, key});
  }

  int Find(int key) {
    for (auto it = vals.rbegin(); it != vals.rend(); it++) {
      if (key != it->second)
        return it->first;
    }
    return -1;
  }
};

class Solution {
public:
  int maximumLength(vector<int> &a, int k) {
    // dp[i][j]: maximum possible length ends at i, with j differences
    // dp[i][j] = dp[x][j] + 1 (x < i and a[x] == a[i])
    // dp[i][j] = dp[x][j - 1] + 1 (x < i and a[x] != a[i])

    int n = a.size(), ans = 0;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int j = 0; j <= k; j++) {
      unordered_map<int, int> seen;
      Map prev;
      for (int i = 0; i < n; i++) {
        // dp[i][j] = dp[x][j] + 1 (if a[x] == a[i])
        auto it = seen.find(a[i]);
        if (it != seen.end())
          umax(dp[i][j], it->second + 1);

        // dp[i][j] = dp[x][j - 1] + 1 (if a[x] != a[i])
        if (j > 0) {
          int res = prev.Find(a[i]);
          if (res != -1)
            umax(dp[i][j], res + 1);
        }

        umax(seen[a[i]], dp[i][j]);
        if (j > 0)
          prev.Add(a[i], dp[i][j - 1]);

        umax(ans, dp[i][j]);
      }
    }
    return ans + 1;
  }
};
