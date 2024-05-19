const int N = 31;

class Solution {
public:
  int waysToReachStair(int k) {
    int n = N;
    vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }

    int ans = 0;
    for (int jump = 0; jump < N; jump++) {
      int sum = (1 << jump) - 1 + 1; // as we start at position 1
      int op = jump + 1;
      if (sum >= k and sum - op <= k)
        ans += C[op][sum - k];
    }
    return ans;
  }
};
