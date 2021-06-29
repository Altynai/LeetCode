class Solution {
public:
  int maxProductDifference(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();
    return a[n - 1] * a[n - 2] - a[0] * a[1];
  }
};
