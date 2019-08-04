class Solution {

  private int zigzag(int[] nums, int start) {
    int n = nums.length, ans = 0;
    for (int i = start; i < n; i += 2) {
      if (i > 0 && nums[i] >= nums[i - 1]) {
        ans += nums[i] - nums[i - 1] + 1;
        nums[i] = nums[i - 1] - 1;
      }
      if (i + 1 < n && nums[i] >= nums[i + 1]) {
        ans += nums[i] - nums[i + 1] + 1;
        nums[i] = nums[i + 1] - 1;
      }
    }
    return ans;
  }

  public int movesToMakeZigzag(int[] nums) {
    return Math.min(zigzag(nums.clone(), 0), zigzag(nums.clone(), 1));
  }
}
