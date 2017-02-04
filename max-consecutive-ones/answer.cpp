class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), max_count = 0, count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                count++;
            } else {
                max_count = std::max(max_count, count);
                count = 0;
            }
        }
        max_count = std::max(max_count, count);
        return max_count;
    }
};