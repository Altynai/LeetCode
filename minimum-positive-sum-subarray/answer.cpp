class Solution {
public:
  int minimumSumSubarray(vector<int> &a, int l, int r) {
    int n = a.size(), ans = -1;
    for (int i = 0; i <= n - l; i++) {
      int sum = accumulate(a.begin() + i, a.begin() + i + l - 1, 0);
      for (int j = i + l - 1; j <= min(n - 1, i + r - 1); j++) {
        sum += a[j];
        if (sum > 0 and (ans == -1 or sum < ans))
          ans = sum;
      }
    }
    return ans;
  }
};
