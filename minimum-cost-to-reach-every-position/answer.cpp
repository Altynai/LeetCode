class Solution {
public:
  vector<int> minCosts(vector<int> &cost) {
    int n = cost.size();
    vector<int> ans(n);

    int best = cost[0];
    for (int i = 0; i < n; i++) {
      ans[i] = min(best, cost[i]);
      best = min(best, cost[i]);
    }
    return ans;
  }
};
