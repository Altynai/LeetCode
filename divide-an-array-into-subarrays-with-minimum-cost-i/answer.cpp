class Solution {
public:
  int minimumCost(vector<int> &a) {
    int ans = INT_MAX, n = a.size();
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j < n; j++)
        ans = min(ans, a[0] + a[i] + a[j]);
    }
    return ans;
  }
};
