template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxScore(int n, int k, vector<vector<int>> &stayScore,
               vector<vector<int>> &travelScore) {
    // dp[i][j]: maximum score after i-th day, at city j
    vector<int> dp(n, 0);
    for (int day = 0; day < k; day++) {
      vector<int> ndp(n, 0);
      for (int cur = 0; cur < n; cur++) {
        // stay in current city
        umax(ndp[cur], dp[cur] + stayScore[day][cur]);
        // move to another city
        for (int nxt = 0; nxt < n; nxt++) {
          if (cur == nxt)
            continue;
          umax(ndp[nxt], dp[cur] + travelScore[cur][nxt]);
        }
      }
      swap(dp, ndp);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
