using int64 = long long;

class Solution {
public:
  long long numberOfSubsequences(vector<int> &nums) {
    // A B C D: A * C = B * D
    // A / B = D / C = 1 / (C / D)

    // if we enumerate A and B, how to quickly find # of C,D pairs ?
    // we can pre-calculate, then how to update with increasing B?
    // as C >= B + 2, with B -> B + 1, we only eliminate pairs for C = B + 2

    int n = nums.size();
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++)
        g[i][j] = g[j][i] = gcd(nums[i], nums[j]);
    }

    map<pair<int, int>, int> cnt;
    for (int c = 4; c < n; c++) {
      for (int d = c + 2; d < n; d++) {
        int x = nums[c] / g[c][d];
        int y = nums[d] / g[c][d];
        cnt[{x, y}]++;
      }
    }

    int64 ans = 0;
    for (int b = 2; b < n; b++) {
      for (int a = b - 2; a >= 0; a--) {
        int x = nums[a] / g[a][b];
        int y = nums[b] / g[a][b];

        auto it = cnt.find({y, x});
        if (it != cnt.end())
          ans += it->second;
      }

      int c = b + 2;
      if (c < n) {
        for (int d = c + 2; d < n; d++) {
          int x = nums[c] / g[c][d];
          int y = nums[d] / g[c][d];
          cnt[{x, y}]--;
        }
      }
    }
    return ans;
  }
};
