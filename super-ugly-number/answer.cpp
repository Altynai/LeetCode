#define i64 long long

class Solution {
private:
    int nextUglyNumber(vector<int>& nums, int nth, int multiplier) {
        int low = 0, mid = 0, high = nums.size() - 1;
        i64 ans = 0;
        while (low <= high) {
            mid = (low + high) >> 1;
            if ((i64)nums[mid] * multiplier > (i64)nth) {
                ans = (i64)nums[mid] * multiplier;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;
        vector<int> nums(1, 1);
        for (int i = 1; i < n; ++i) {
            int nth = nums[i - 1], ans = INT_MAX;
            for (int j = 0; j < primes.size(); ++j)
                ans = min(ans, nextUglyNumber(nums, nth, primes[j]));
            nums.push_back(ans);
        }
        return nums[n - 1];
    }
};