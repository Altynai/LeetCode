class Solution {
public:
  int minOperations(vector<int> &a) {
    int ans = 0, n = a.size();
    for (int i = 0; i + 2 < n; i++) {
      if (a[i] == 0) {
        ans++;
        a[i + 1] ^= 1;
        a[i + 2] ^= 1;
      }
    }
    if (a[n - 2] == 0 or a[n - 1] == 0)
      return -1;
    return ans;
  }
};
