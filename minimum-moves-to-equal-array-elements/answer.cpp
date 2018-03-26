class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i)
            moves += nums[i] - nums[0];
        return moves;
    }
};