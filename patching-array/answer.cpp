class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0, i = 0;
        long long cover = 0;
        while (cover < n) {
            if (i < nums.size() && nums[i] <= cover + 1)
                cover += nums[i++];
            else
                cover += cover + 1, count++;
        }
        return count;
    }
};