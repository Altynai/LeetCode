class Solution {
public:
  int findGCD(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return gcd(nums[0], nums.back());
  }
};
