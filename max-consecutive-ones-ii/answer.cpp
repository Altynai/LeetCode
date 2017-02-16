class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> ranges;
        for (int i = 0; i < n;) {
            if (nums[i] == 0) {
                i++;
                continue;
            }
            int start = i;
            while (i < n && nums[i] == 1)
                i++;
            int end = i;
            ranges.push_back(make_pair(start, end));
        }
        if (ranges.size() == 0)
            return n > 0 ? 1 : 0;
        else if (ranges.size() == 1) {
            int ans = ranges[0].second - ranges[0].first;
            return ans == n ? ans : ans + 1;
        } else {
            int ans = ranges[0].second - ranges[0].first;
            for (int i = 1; i < ranges.size(); ++i) {
                pair<int, int> previous = ranges[i - 1];
                pair<int, int> current = ranges[i];
                ans = max(ans, current.second - current.first + 1);
                if (current.first - 1 == previous.second)
                    ans = max(ans, current.second - previous.first);
            }
            return ans;
        }
    }
};