
class Solution {
private:
    bool overlap(const Interval &lh, const Interval &rh) {
        return lh.start <= rh.start && rh.start <= lh.end;
    }

    int insertIndex(const vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        int low = 0, high = n - 1, mid, index = -1;
        while (low <= high) {
            mid = (low + high ) >> 1;
            if (intervals[mid].start >= newInterval.start) {
                index = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return index;
    }

public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n = intervals.size();
        int index = insertIndex(intervals, newInterval);
        if (index == -1)
            intervals.push_back(newInterval);
        else
            intervals.insert(intervals.begin() + index, newInterval);
        vector<Interval> result;
        Interval now = intervals[0];
        for (int i = 1; i <= n; i++) {
            if (overlap(now, intervals[i]))
                now.end = std::max(now.end, intervals[i].end);
            else {
                result.push_back(now);
                now = intervals[i];
            }
        }
        result.push_back(now);
        return result;
    }
};