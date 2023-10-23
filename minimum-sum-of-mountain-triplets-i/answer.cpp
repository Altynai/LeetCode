class Solution {
public:
  int minimumSum(vector<int> &a) {
    int n = a.size(), ans = INT_MAX;
    for (int j = 1; j < n - 1; j++) {
      for (int i = 0; i < j; i++) {
        for (int k = j + 1; k < n; k++) {
          if (a[i] < a[j] and a[j] > a[k])
            ans = min(ans, a[i] + a[j] + a[k]);
        }
      }
    }
    if (ans == INT_MAX)
      ans = -1;
    return ans;
  }
};
