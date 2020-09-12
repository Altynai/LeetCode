class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        const int inf = 1e9 + 10;
        
        int n = s.size();
        vector<int> dp(27, inf);
        dp[s[0] - 'a'] = 0;
        dp[26] = cost[0];

        for (int i = 1; i < n; i++) {
            vector<int> dp2(27, inf);
            for (int j = 0; j <= 26; j++) {
                if (s[i] - 'a' != j)
                    dp2[s[i] - 'a'] = min(dp2[s[i] - 'a'], dp[j]);
                dp2[j] = min(dp2[j], dp[j] + cost[i]);
            }
            dp = dp2;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
