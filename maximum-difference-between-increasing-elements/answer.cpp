class Solution {
public:
  int maximumDifference(vector<int> &a) {
    int n = a.size(), ans = -1, mn = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] > mn)
        ans = max(ans, a[i] - mn);
      mn = min(a[i], mn);
    }
    return ans;
  }
};
