const int MOD = 1000000000 + 7;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> shared;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(shared));        
        
        int ans = 0;
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0;
        
        auto update = [&](long long a, long long b) {
            ans = (ans + max(a, b) % MOD) % MOD;
        };

        for (int k = 0; k < shared.size(); k++) {
            int nxt = shared[k];
            sum1 = sum2 = 0;
            while (nums1[i] != nxt) sum1 += nums1[i++];
            sum1 += nums1[i++];
            while (nums2[j] != nxt) sum2 += nums2[j++];
            sum2 += nums2[j++];
            update(sum1, sum2);
        }
        
        sum1 = sum2 = 0;
        while (i < n) sum1 += nums1[i++];
        while (j < m) sum2 += nums2[j++];
        update(sum1, sum2);
        return ans;
    }
};
