class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if (n == 0)
            return 0;
        int max_time = timeSeries[0], ans = 0;
        for (int i = 0; i < n; ++i) {
            int start = timeSeries[i];
            int end = start + duration;
            if (start >= max_time) {
                ans += duration;
            } else {
                ans += std::max(0, end - max_time);
            }
            max_time = std::max(max_time, end);
        }
        return ans;
    }
};