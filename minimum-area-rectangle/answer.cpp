#define PII pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define FOR(i, s, t) for (int i = (s); i < (t); i++)

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        set<PII> seen;
        for (vector<int>& point : points)
            seen.insert(MP(point[0], point[1]));
        
        int ans = -1;
        FOR(i, 0, n) {
            PII a = MP(points[i][0], points[i][1]);
            FOR(j, i + 1, n) {
                PII b = MP(points[j][0], points[j][1]);
                if (a.first == b.first || a.second == b.second)
                    continue;
                PII c = MP(points[i][0], points[j][1]);
                PII d = MP(points[j][0], points[i][1]);
                if (seen.find(c) != seen.end() && seen.find(d) != seen.end()) {
                    int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
                    if (ans == -1 || ans > area)
                        ans = area;
                }
            }
        }
        return ans == -1 ? 0 : ans;
    }
};
