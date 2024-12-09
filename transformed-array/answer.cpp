class Solution {
public:
  vector<int> constructTransformedArray(vector<int> &a) {
    int n = a.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      if (a[i] > 0)
        ans[i] = a[(i + a[i]) % n];
      else if (a[i] < 0)
        ans[i] = a[((i + a[i]) % n + n) % n];
    }
    return ans;
  }
};
