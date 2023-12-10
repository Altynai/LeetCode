class Solution {
public:
  int countTestedDevices(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        ans++;
        for (int j = i + 1; j < n; j++)
          a[j] = max(a[j] - 1, 0);
      }
    }
    return ans;
  }
};
