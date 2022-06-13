class Solution {
public:
  double calculateTax(vector<vector<int>> &a, int income) {
    double ans = 0;
    int n = a.size(), pre = 0;
    for (int i = 0; i < n; i++) {
      if (income >= a[i][0])
        ans += 0.01 * a[i][1] * (a[i][0] - pre);
      else {
        ans += 0.01 * a[i][1] * (income - pre);
        break;
      }
      pre = a[i][0];
    }
    return ans;
  }
};
