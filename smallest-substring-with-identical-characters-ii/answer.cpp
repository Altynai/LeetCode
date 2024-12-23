template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minLength(string s, int numOps) {
    int n = s.size();

    // if answer is 1, then it's alternate
    {
      vector<int> dp(2, 0);
      dp[(s[0] - '0') ^ 1] = 1;
      for (int i = 1; i < n; i++) {
        vector<int> ndp(2, INT_MAX);
        int d = s[i] - '0';
        for (int x = 0; x < 2; x++) {
          if (x == d)
            umin(ndp[d ^ 1], dp[x] + 1);
          else
            umin(ndp[d], dp[x]);
        }
        swap(dp, ndp);
      }
      if (min(dp[0], dp[1]) <= numOps)
        return 1;
    }

    // if answer is 2
    {
      vector<vector<int>> dp(2, vector<int>(2, INT_MAX));
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          dp[x][y] = int(s[0] - '0' != x) + int(s[1] - '0' != y);
        }
      }
      for (int i = 2; i < n; i++) {
        vector<vector<int>> ndp(2, vector<int>(2, INT_MAX));
        int d = s[i] - '0';
        for (int x = 0; x < 2; x++) {
          for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 2; z++) {
              if (x == y and y == z)
                continue;
              umin(ndp[y][z], dp[x][y] + int(d != z));
            }
          }
        }
        swap(dp, ndp);
      }
      int best = INT_MAX;
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          umin(best, dp[x][y]);
        }
      }
      if (best <= numOps)
        return 2;
    }

    // answer is >= 3, we can just binary search
    map<int, int> freq;
    for (int i = 0, j = i; i < n; i = j) {
      while (j < n and s[j] == s[i])
        j++;
      freq[j - i]++;
    }
    vector<pair<int, int>> p;
    for (auto [k, v] : freq)
      p.push_back({k, v});

    int m = p.size(), ans = -1;
    for (int l = 3, r = p[m - 1].first; l <= r;) {
      int mid = (l + r) / 2, ops = 0;
      for (int i = m - 1; i >= 0 and p[i].first > mid; i--) {
        auto [len, cnt] = p[i];
        ops += len / (mid + 1) * cnt;
      }
      if (ops <= numOps)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
