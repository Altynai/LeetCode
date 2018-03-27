class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int head = 0, tail = 0, best = 0;
        
        // init
        vector<int> added(n, 0);
        for (int i = 0; i < k; i++)
            added[0] += nums[i];
        for (int i = 1; i + k <= n; i++)
            added[i] = added[i - 1] - nums[i - 1] + nums[i + k - 1];
        
        // left
        vector<int> left(n, 0);
        best = added[0];
        for (int i = 1; i + k <= n; i++) {
            left[i] = added[i] > best ? i : left[i - 1];
            best = max(added[i], best);
        }
    
        // right
        vector<int> right(n, 0);
        best = added[n - k];
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            right[i] = added[i] > best ? i : right[i + 1];
            best = max(added[i], best);
        }
        
        // sum up
        vector<int> ans(3, -1);
        best = 0;
        for (int i = k; i <= n - 2 * k; i++) {
            int lp = left[i - k], rp = right[i + k];
            int tmp = added[lp] + added[i] + added[rp];
            if (ans[0] == -1 || tmp > best) {
                ans[0] = lp;
                ans[1] = i;
                ans[2] = rp;
                best = tmp;
            }
        }
        return ans;
    }
};