class Solution {
public:
  int minimumOperations(vector<int> &a, int start, int goal) {
    int n = a.size();

    const int N = 1000;
    vector<int> dp(N + 1, INT_MAX);

    dp[start] = 0;
    deque<int> dq = {start};

    auto enque = [&](int val, int steps) {
      if (0 <= val && val <= N && dp[val] == INT_MAX) {
        dp[val] = steps;
        dq.push_back(val);
      }
    };

    while (!dq.empty()) {
      int i = dq.front();
      dq.pop_front();
      for (int val : a) {
        enque(i + val, dp[i] + 1);
        enque(i - val, dp[i] + 1);
        enque(i ^ val, dp[i] + 1);
      }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= N; i++) {
      if (dp[i] == INT_MAX)
        continue;
      if (i == goal)
        ans = min(ans, dp[i]);
      for (int x : a) {
        if (i + x == goal || i - x == goal || (i ^ x) == goal)
          ans = min(ans, dp[i] + 1);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
