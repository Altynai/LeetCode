class Solution {
private:
    map<int, vector<int>> seen;

    int solve(int p, int color) {
        vector<int>& vi = seen[color];
        if (vi.size() == 0)
            return -1;
        int ans = -1;
        auto it = lower_bound(vi.begin(), vi.end(), p);
        if (it != vi.end())
            ans = (ans == -1) ? abs(p - *it) : min(ans, abs(p - *it));
        if (it != vi.begin()) {
            --it;
            ans = (ans == -1) ? abs(p - *it) : min(ans, abs(p - *it));
        }
        return ans;
    }

public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        seen.clear();
        for (int i = 0; i < colors.size(); i++)
            seen[colors[i]].push_back(i);
        vector<int> ans(queries.size(), -1);
        for(int i = 0; i < queries.size(); i++)
            ans[i] = solve(queries[i][0], queries[i][1]);
        return ans;
    }
};
