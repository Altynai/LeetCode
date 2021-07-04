class Solution {
public:
  vector<int> buildArray(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
      ans[i] = a[a[i]];
    return ans;
  }
};
