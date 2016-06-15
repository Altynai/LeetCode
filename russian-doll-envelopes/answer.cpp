class Solution {
private:
    bool fitInto(pair<int, int>& lh, pair<int, int>& rh) {
        return lh.first < rh.first && lh.second < rh.second;
    }

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        int answer = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (fitInto(envelopes[j], envelopes[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    answer = max(answer, dp[i]);
                }
            }
        }
        return answer;
    }
};