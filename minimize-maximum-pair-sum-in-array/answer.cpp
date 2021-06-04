class Solution {
public:
  int minPairSum(vector<int> &a) {
    sort(a.begin(), a.end());
    int n = a.size(), ans = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--)
      ans = max(ans, a[i] + a[j]);
    return ans;
  }
};
