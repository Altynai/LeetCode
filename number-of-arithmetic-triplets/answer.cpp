class Solution {
public:
  int arithmeticTriplets(vector<int> &a, int diff) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if (a[j] - a[i] == diff and a[k] - a[j] == diff)
            ans++;
        }
      }
    }
    return ans;
  }
};
