class Solution {
public:
  vector<int> getAverages(vector<int> &a, int k) {
    int n = a.size(), len = k * 2 + 1;
    vector<int> ans(n, -1);
    long long sum = accumulate(a.begin(), a.begin() + min(n, len), 0LL);
    for (int i = k; i + k < n; i++) {
      if (i > k) {
        sum -= a[i - k - 1];
        sum += a[i + k];
      }
      ans[i] = sum / len;
    }
    return ans;
  }
};
