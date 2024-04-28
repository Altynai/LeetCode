class Solution {
public:
  int addedInteger(vector<int> &nums1, vector<int> &nums2) {
    int x = *min_element(nums1.begin(), nums1.end());
    int y = *min_element(nums2.begin(), nums2.end());
    return y - x;
  }
};
