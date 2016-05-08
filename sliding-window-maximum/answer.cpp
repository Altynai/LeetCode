class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0)
            return vector<int>();
        deque<pair<int, int> > q;
        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            while (!q.empty() && q.front().first <= i - k)
                q.pop_front();
            while (!q.empty() && q.back().second <= nums[i])
                q.pop_back();
            q.push_back(make_pair(i, nums[i]));
            answer[i] = q.front().second;
        }
        return vector<int>(answer.begin() + k - 1, answer.end());
    }
};