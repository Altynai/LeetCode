using int64 = long long;

class Solution {
public:
  int64 countQuadruplets(vector<int> &a) {
    const int M = *max_element(a.begin(), a.end());

    int n = a.size();

    // f[i][j]: # of values <= j in a[1 ... i]
    vector<vector<int>> f(n + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= n; i++) {
      int val = a[i - 1];
      for (int j = 0; j <= M; j++)
        f[i][j] = f[i - 1][j] + int(j >= val);
    }

    // g[i][j]: # of values >= j in a[i ... n]
    vector<vector<int>> g(n + 2, vector<int>(M + 2, 0));
    for (int i = n; i >= 1; i--) {
      int val = a[i - 1];
      for (int j = M; j >= 0; j--)
        g[i][j] = g[i + 1][j] + int(j <= val);
    }

    int64 ans = 0;
    for (int j = 2; j + 2 <= n; j++) {
      for (int k = j + 1; k + 1 <= n; k++) {
        if (a[k - 1] >= a[j - 1])
          continue;

        ans += 1LL * f[j - 1][a[k - 1] - 1] * g[k + 1][a[j - 1] + 1];
      }
    }
    return ans;
  }
};
