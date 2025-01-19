class Solution {
public:
  int subarraySum(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
      ans += accumulate(a.begin() + max(0, i - a[i]), a.begin() + i + 1, 0);
    return ans;
  }
};
