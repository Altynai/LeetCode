class Solution {
public:
  vector<int> applyOperations(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, 0);
    for (int i = 0, j = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        a[i] *= 2;
        a[i + 1] = 0;
      }
      if (a[i])
        ans[j++] = a[i];
      if (i == n - 2 and a[i + 1])
        ans[j++] = a[i + 1];
    }
    return ans;
  }
};
