class Solution {
public:
  int maxSubarrays(vector<int> &a) {
    int n = a.size(), ans = 0;
    int val = -1;
    for (int i = 0; i < n; i++) {
      val = (val == -1 ? a[i] : (val & a[i]));
      if (val == 0)
        ans++, val = -1;
    }
    return max(ans, 1);
  }
};
