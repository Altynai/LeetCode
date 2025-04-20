class Solution {
public:
  int maximumPossibleSize(vector<int> &a) {
    int n = a.size(), ans = 0, pre = 0;
    for (int i = 0; i < n; i++) {
      if (pre <= a[i])
        ans++, pre = a[i];
    }
    return ans;
  }
};
