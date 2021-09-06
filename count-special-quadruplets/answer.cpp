class Solution {
public:
  int countQuadruplets(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          for (int d = k + 1; d < n; d++) {
            if (a[i] + a[j] + a[k] == a[d])
              ans++;
          }
        }
      }
    }
    return ans;
  }
};
