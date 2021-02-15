class Solution {
public:
  int minimumSize(vector<int> &nums, int maxOperations) {
    int ans = -1;
    for (int l = 1, r = *max_element(nums.begin(), nums.end()); l <= r;) {
      int m = (l + r) >> 1, cnt = 0;
      for (int num : nums) {
        if (num % m == 0)
          cnt += num / m - 1;
        else
          cnt += num / m;
      }
      if (cnt <= maxOperations) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};
