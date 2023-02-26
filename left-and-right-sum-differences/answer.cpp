class Solution {
public:
  vector<int> leftRigthDifference(vector<int> &a) {
    int n = a.size();
    vector<int> rsum(n, 0);
    for (int i = n - 2; i >= 0; i--)
      rsum[i] = rsum[i + 1] + a[i + 1];

    vector<int> ans(n, 0);
    int lsum = 0;
    for (int i = 0; i < n; i++) {
      ans[i] = abs(lsum - rsum[i]);
      lsum += a[i];
    }
    return ans;
  }
};
