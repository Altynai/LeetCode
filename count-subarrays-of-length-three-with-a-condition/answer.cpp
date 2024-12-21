class Solution {
public:
  int countSubarrays(vector<int> &a) {
    int n = a.size(), ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if ((a[i - 1] + a[i + 1]) * 2 == a[i])
        ans++;
    }
    return ans;
  }
};
