class Solution {
public:
  int maxHeight(vector<vector<int>> &cuboids) {
    int n = cuboids.size();
    for (vector<int> &c : cuboids)
      sort(c.begin(), c.end());
    sort(cuboids.begin(), cuboids.end());

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
      dp[i] = cuboids[i][2];

      for (int j = 0; j < i; j++) {
        if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] &&
            cuboids[i][2] >= cuboids[j][2])
          dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
