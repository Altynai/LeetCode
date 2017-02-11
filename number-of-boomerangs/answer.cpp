class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n <= 2)
            return 0;
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            map<int, vector<int>> counter;
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                int dx = (points[i].first - points[j].first);
                int dy = (points[i].second - points[j].second);
                int d = dx * dx + dy * dy;
                counter[d].push_back(j);
            }
            for (auto it = counter.begin(); it != counter.end(); ++it) {
                int m = (it->second).size();
                ans += m >= 2 ? m * (m - 1) : 0;
            }
        }
        return ans;
    }
};