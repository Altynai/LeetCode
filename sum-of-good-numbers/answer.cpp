class Solution {
public:
  int sumOfGoodNumbers(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      if (i - k >= 0 and a[i] <= a[i - k])
        continue;
      if (i + k < n and a[i] <= a[i + k])
        continue;
      ans += a[i];
    }
    return ans;
  }
};
