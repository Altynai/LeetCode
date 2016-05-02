class NumArray {
private:
    std::vector<int> sums;
public:
    NumArray(vector<int> &nums) {
        sums = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            sums[i] = i == 0 ? nums[0] : sums[i - 1] + nums[i];
    }

    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);