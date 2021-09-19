class Solution {
public:
  int countKDifference(vector<int> &a, int k) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(a[i] - a[j]) == k)
          ans++;
      }
    }
    return ans;
  }
};
