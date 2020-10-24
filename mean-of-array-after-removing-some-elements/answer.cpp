class Solution {
public:
  double trimMean(vector<int> &a) {
    int n = a.size();
    int m = n / 20;
    sort(a.begin(), a.end());
    double ans = accumulate(a.begin() + m, a.begin() + n - m, 0.0);
    return ans / (n - m - m);
  }
};
