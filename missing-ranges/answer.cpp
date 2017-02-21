class Solution {
public:
    string findRange(int start, int end, bool startShows, bool endShows) {
        int diff = end - start;
        if (diff == 0)
            return "";
        else if (diff == 1) {
            if (startShows && endShows)
                return "";
            else if (startShows)
                return to_string(end);
            else
                return to_string(start);
        } else if (diff == 2) {
            if (startShows && endShows)
                return to_string(start + 1);
            else if (startShows)
                return to_string(start + 1) + "->" + to_string(end);
            else
                return to_string(start) + "->" + to_string(end - 1);
        } else {
            string a =  to_string(startShows ? start + 1 : start);
            string b = to_string(endShows ? end - 1 : end);
            return a + "->" + b;
        }
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        if (nums.size() == 0) {
            if (lower == upper)
                ranges.push_back(to_string(lower));
            else
                ranges.push_back(to_string(lower) + "->" + to_string(upper));
            return ranges;
        }
        if (nums.front() != lower) {
            string range = findRange(lower, nums.front(), false, true);
            if (range != "")
                ranges.push_back(range);
        }
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            string range = findRange(nums[i - 1], nums[i], true, true);
            if (range != "")
                ranges.push_back(range);
        }
        if (nums.back() != upper) {
            string range = findRange(nums.back(), upper, true, false);
            if (range != "")
                ranges.push_back(range);
        }
        return ranges;
    }
};