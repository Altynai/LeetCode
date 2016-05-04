class NumArray {
private:
    std::vector<int> sums;
    int n;
    int lowBit(int i) {
        return i & (-i);
    }
    int sum(int i) {
        int answer = 0;
        while (i >= 1) {
            answer += sums[i];
            i -= this->lowBit(i);
        }
        return answer;
    }

public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        sums = std::vector<int>(n + 1, 0);
        for (int i = 0; i < n; ++i)
            this->update(i, nums[i]);
    }

    void update(int i, int val) {
        val -= this->sumRange(i, i);
        i++;
        while (i <= n) {
            sums[i] += val;
            i += this->lowBit(i);
        }
    }

    int sumRange(int i, int j) {
        i++, j++;
        return this->sum(j) - this->sum(i - 1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);