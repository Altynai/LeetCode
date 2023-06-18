class Solution {
public:
  int findValueOfPartition(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size(), ans = INT_MAX;
    for (int i = 1; i < n; i++)
      ans = min(ans, a[i] - a[i - 1]);
    return ans;
  }
};
