class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &q) {
    int n = s.size();
    vector<int> candles;
    for (int i = 0; i < n; i++) {
      if (s[i] == '|')
        candles.push_back(i);
    }

    int m = q.size();
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
      int l = q[i][0], r = q[i][1];
      int left =
          lower_bound(candles.begin(), candles.end(), l) - candles.begin();
      int right =
          upper_bound(candles.begin(), candles.end(), r) - candles.begin() - 1;
      if (left < right) {
        ans[i] = candles[right] - candles[left] + 1 - (right - left + 1);
      }
    }
    return ans;
  }
};
