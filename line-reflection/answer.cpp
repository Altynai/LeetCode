#define x first
#define y second

bool compare(const pair<int, int>& lh, const pair<int, int>& rh) {
    if (lh.y == rh.y)
        return lh.x <= rh.x;
    return lh.y < rh.y;
}

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n <= 1)
            return true;
        set<pair<int, int>> stp(points.begin(), points.end());
        points = vector<pair<int, int>>(stp.begin(), stp.end());
        n = points.size();
        sort(points.begin(), points.end(), compare);
        int symmetry = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && points[j].y == points[i].y)
                j++;
            if (i == 0)
                symmetry = points[i].x + points[j - 1].x;
            int ii = i, jj = j - 1;
            while (ii <= jj) {
                if (points[ii].x + points[jj].x != symmetry)
                    return false;
                ii++, jj--;
            }
            i = j;
        }
        return true;
    }
};