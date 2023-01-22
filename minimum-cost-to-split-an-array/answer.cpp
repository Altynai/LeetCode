template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

class Solution {
public:
  int minCost(vector<int> &a, int k) {
    int n = a.size();
    vector<vector<int>> score(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      vector<int> freq(n, 0);
      int s = 0;
      for (int j = i; j < n; j++) {
        int x = ++freq[a[j]];
        if (x == 2)
          s += 2;
        else if (x > 2)
          s++;
        score[i][j] = s;
      }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = k + score[0][i];
      for (int j = i; j > 0; j--)
        umin(dp[i], dp[j - 1] + k + score[j][i]);
    }
    return dp[n - 1];
  }
};
