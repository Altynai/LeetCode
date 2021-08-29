class Solution {
public:
  string kthLargestNumber(vector<string> &nums, int k) {
    sort(nums.begin(), nums.end(), [](const string &lh, const string &rh) {
      if (lh.size() != rh.size())
        return lh.size() < rh.size();
      return lh < rh;
    });
    return nums[nums.size() - k];
  }
};
