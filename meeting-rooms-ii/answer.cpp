/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1)
            return n;
        vector<pair<int, int>> items;
        for (int i = 0; i < n; ++i) {
            Interval& interval = intervals[i];
            items.push_back(make_pair(interval.start, 1));
            items.push_back(make_pair(interval.end, -1));
        }
        int ans = 0, sum = 0;
        sort(items.begin(), items.end());
        for (int i = 0; i < items.size(); ++i) {
            pair<int, int>& item = items[i];
            sum += item.second;
            if (item.second == 1)
                ans = max(ans, sum);
        }
        return ans;
    }
};