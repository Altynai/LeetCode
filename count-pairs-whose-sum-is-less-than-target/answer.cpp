class Solution {
public:
  int countPairs(vector<int> &a, int target) {
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[i] + a[j] < target)
          ans++;
      }
    }
    return ans;
  }
};
