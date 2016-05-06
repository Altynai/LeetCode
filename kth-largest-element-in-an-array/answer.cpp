class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > queue;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            queue.push(nums[i]);
            if (queue.size() > k)
                queue.pop();
        }
        return queue.top();
    }
};