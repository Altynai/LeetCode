class Solution {
public:
  int minGroups(vector<vector<int>> &intervals) {
    map<int, int> sum;
    for (auto &each : intervals) {
      sum[each[0]]++;
      sum[each[1] + 1]--;
    }
    int ans = 0, now = 0;
    for (auto [k, v] : sum) {
      now += v;
      ans = max(ans, now);
    }
    return ans;
  }
};
