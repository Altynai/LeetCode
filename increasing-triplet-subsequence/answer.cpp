class Solution {
private:
    void updatePair(int& first, int &second, int smallest, int value) {
        if (value < second && first < value) {
            second = value;
            first = min(first, smallest);
        }
        else if (value < second && smallest < value) {
            first = min(first, smallest);
            second = value;
        }
    }

public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;
        int smallest = nums[0], first = nums[0], second = nums[0];
        int i = 1;
        // find second
        while (i < n) {
            if (nums[i] > smallest) {
                first = smallest;
                second = nums[i];
                break;
            }
            smallest = min(smallest, nums[i]);
            i++;
        }
        if (i == n)
            return false;
        i++;
        while (i < n) {
            if (nums[i] > second)
                return true;
            updatePair(first, second, smallest, nums[i]);
            smallest = min(smallest, nums[i]);
            i++;
        }
        return false;
    }
};