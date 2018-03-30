#define int64 long long

class Solution {
private:
    int countSlice(vector<int>& nums, int64 target) {
        int count = 0;
        int64 sum = 0;
        for (auto num : nums) {
            if (num > target)
                return -1;
            if (sum + num <= target)
                sum += num;
            else {
                count++;
                sum = num;
            }
        }
        if (sum <= target)
            count++;
        return count;
    }
        
public:
    int splitArray(vector<int>& nums, int m) {
        int64 low = 0, mid = 0, high = 0;
        int64 best = -1;
        for (auto num : nums)
            high += num;
        while (low <= high) {
            mid = (low + high) >> 1;
            int count = countSlice(nums, mid);
            if (count != -1 && count <= m) {
                if (best == -1 || mid < best)
                    best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return best;
    }
};