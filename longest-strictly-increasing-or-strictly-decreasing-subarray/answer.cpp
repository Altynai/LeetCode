class Solution {
public:
  int longestMonotonicSubarray(vector<int> &a) {
    int n = a.size(), ans = 1;
    for (int t = 0; t < 2; t++) {
      for (int i = 0; i < n;) {
        int j = i + 1;
        while (j < n and a[j] > a[j - 1])
          j++;
        ans = max(ans, j - i);
        i = j;
      }
      reverse(a.begin(), a.end());
    }
    return ans;
  }
};
