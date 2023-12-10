class Solution {
public:
  int maxSubarrayLength(vector<int> &a, int k) {
    int n = a.size(), ans = 0;
    unordered_map<int, int> cnt;
    for (int r = 0, l = 0; r < n; r++) {
      if (k == cnt[a[r]]++) {
        while (l < r and cnt[a[r]] > k)
          cnt[a[l++]]--;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
