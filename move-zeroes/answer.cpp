class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (nums[i] != 0)
                nonzero++;
        int moved = 0;
        for (int i = 0; i < n; ++i) {
            if (moved >= nonzero)
                break;
            if (nums[i] != 0)
                nums[moved++] = nums[i];
        }
        for (int i = nonzero; i < n; ++i) 
            nums[i] = 0;
    }
};