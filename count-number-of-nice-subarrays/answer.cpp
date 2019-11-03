class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1)
                odd.push_back(i);
        }
        
        int m = odd.size();
        if (k > m)
            return 0;
        int ans = 0;
        for (int i = 0; i + k - 1 < m; i++) {
            int a = (i == 0) ? odd[i] + 1 : odd[i] - odd[i - 1];
            int j = i + k - 1;
            int b = (j == m - 1) ? n - odd[j] : odd[j + 1] - odd[j];
            ans += a * b;
        }
        return ans;
    }
};
