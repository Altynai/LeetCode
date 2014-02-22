
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool intervalComparetor(const Interval &lh, const Interval &rh) {
    if (lh.start != rh.start)
        return lh.start < rh.start;
    else
        return lh.end < rh.end;
}

class Solution {
private:
    bool overlap(const Interval &lh, const Interval &rh) {
        return lh.start <= rh.start && rh.start <= lh.end;
    }

public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int n = intervals.size();
        if (n == 0)
            return intervals;
        std::sort(intervals.begin(), intervals.end(), intervalComparetor);
        vector<Interval> result;
        Interval now = intervals[0];
        for (int i = 1; i < n; i++) {
        	if(overlap(now, intervals[i]))
        		now.end = std::max(now.end, intervals[i].end);
        	else{
        		result.push_back(now);
        		now = intervals[i];
        	}
        }
		result.push_back(now);
        return result;
    }
};