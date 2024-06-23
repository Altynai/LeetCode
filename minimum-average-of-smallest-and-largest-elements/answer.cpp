class Solution {
public:
  double minimumAverage(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    double ans = double(a[0] + a[n - 1]) / 2;
    for (int i = 1, j = n - 2; i < j; i++, j--)
      ans = min(ans, double(a[i] + a[j]) / 2);
    return ans;
  }
};
