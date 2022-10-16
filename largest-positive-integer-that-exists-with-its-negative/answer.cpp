class Solution {
public:
  int findMaxK(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = n - 1; i >= 0 and a[i] > 0; i--) {
      if (*lower_bound(a.begin(), a.end(), -a[i]) == -a[i])
        return a[i];
    }
    return -1;
  }
};
