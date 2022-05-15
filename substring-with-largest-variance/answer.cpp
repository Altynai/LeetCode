const int N = 26;

class Solution {
public:
  int largestVariance(string s) {
    int n = s.size(), ans = 0;
    vector<int> pref_min(n + 1, INT_MAX);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j)
          continue;

        int now = 0, last_i = -1, last_j = -1;
        for (int k = 1; k <= n; k++) {
          if (s[k - 1] - 'a' == i)
            last_i = k, now++;
          if (s[k - 1] - 'a' == j)
            last_j = k, now--;

          pref_min[k] = min(now, pref_min[k - 1]);

          if (last_i != -1 and last_j != -1) {
            ans = max(ans, now);
            int p = min(last_i, last_j);
            if (pref_min[p - 1] != INT_MAX)
              ans = max(ans, now - pref_min[p - 1]);
          }
        }
      }
    }
    return ans;
  }
};
