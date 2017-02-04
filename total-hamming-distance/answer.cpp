class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        const int N = 32;
        vector<int> ones(N);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < N; ++j) {
                if (nums[i] & (1 << j))
                    ones[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans += ones[i] * (n - ones[i]);
        return ans;
    }
};