class Solution {
public:
    int* fenwick;

    void update(int i, int n, int value) {
        while (i <= n) {
            fenwick[i] = max(fenwick[i], value);
            i += i & (-i);
        }
    }

    int get(int i) {
        int ans = 0;
        while (i >= 1) {
            ans = max(ans, fenwick[i]);
            i -= i & (-i);
        }
        return ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        unordered_set<int> seen(startTime.begin(), startTime.end());
        seen.insert(endTime.begin(), endTime.end());
        seen.insert(0);

        int m = seen.size();
        vector<int> t(seen.begin(), seen.end());
        sort(t.begin(), t.end());

        vector<pair<int, pair<int, int>>> pairs(n);
        for (int i = 0; i < n; i++) {
            int s = lower_bound(t.begin(), t.end(), startTime[i]) - t.begin();
            int e = lower_bound(t.begin(), t.end(), endTime[i]) - t.begin();
            pairs[i] = make_pair(e, make_pair(s, profit[i]));
        }
        sort(pairs.begin(), pairs.end());

        vector<int> dp(m, 0);
        fenwick = new int[m];
        for (int i = 0; i < n; i++) {
            int e = pairs[i].first;
            int s = pairs[i].second.first;
            int p = pairs[i].second.second;
            dp[e] = max(dp[e], get(s) + p);
            update(e, m - 1, dp[e]);
        }
        return get(m - 1);
    }
};
