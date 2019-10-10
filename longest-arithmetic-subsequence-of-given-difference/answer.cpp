class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, vector<int>> seen;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            seen[arr[i]].push_back(i);
        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            int val = arr[i] + difference, pre = 0;
            auto it = seen.find(val);
            if (it != seen.end()) {
                vector<int>& p = it->second;
                auto k = lower_bound(p.begin(), p.end(), i + 1);
                if (k != p.end())
                    pre = dp[*k];
            }
            dp[i] = max(dp[i], pre + 1);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
