const int MOD = 1e9 + 7;

void add(int &x, int y) { x = (x + y % MOD) % MOD; }

void sub(int &x, int y) { add(x, MOD - y); }

class Solution {
private:
  int count(string s, int min_sum, int max_sum) {
    const int N = 400 + 1;
    vector<vector<int>> dp(N, vector<int>(2, 0));

    int d = s[0] - '0';
    for (int i = 0; i < d; i++)
      dp[i][0] = 1;
    dp[d][1] = 1;

    int n = s.size();
    for (int i = 1; i < n; i++) {
      vector<vector<int>> ndp(N, vector<int>(2, 0));
      d = s[i] - '0';
      for (int sum = 0; sum < N; sum++) {
        // less
        for (int i = 0; i <= 9; i++) {
          if (sum >= i) {
            add(ndp[sum][0], dp[sum - i][0]);
            if (i < d)
              add(ndp[sum][0], dp[sum - i][1]);
          }
        }
        // equal
        if (sum >= d)
          add(ndp[sum][1], dp[sum - d][1]);
      }
      swap(dp, ndp);
    }
    int ans = 0;
    for (int i = min_sum; i <= max_sum; i++) {
      add(ans, dp[i][0]);
      add(ans, dp[i][1]);
    }
    return ans;
  }

public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    int ans = count(num2, min_sum, max_sum);
    sub(ans, count(num1, min_sum, max_sum));

    // check if num1 itself is valid
    int sum = 0;
    for (char c : num1)
      sum += c - '0';
    if (min_sum <= sum and sum <= max_sum)
      add(ans, 1);

    return ans;
  }
};
