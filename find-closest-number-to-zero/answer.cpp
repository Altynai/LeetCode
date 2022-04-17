class Solution {
public:
  int findClosestNumber(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();
    int p = lower_bound(a.begin(), a.end(), 0) - a.begin();

    if (p == n)
      return a[n - 1];
    else if (p == 0)
      return a[0];
    return abs(a[p]) <= abs(a[p - 1]) ? a[p] : a[p - 1];
  }
};
