/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comparator(const Interval& a, const Interval& b) {
    if (a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<Interval> points;
        for (auto interval : intervals) {
            points.push_back(Interval(interval.start, 1));
            points.push_back(Interval(interval.end, -1));
        }
        sort(points.begin(), points.end(), comparator);
        int sum = 0;
        for (auto point : points) {
            sum += point.end;
            if (sum > 1)
                return false;
        }
        return true;
    }
};