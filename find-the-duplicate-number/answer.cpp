class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 1, mid, count;
        int answer = 0;
        while (low <= high) {
            if (low == high) {
                answer = low;
                break;
            }
            mid = (low + high) >> 1;
            count = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] >= low && nums[i] <= mid)
                    count++;
            }
            if (count > mid - low + 1)
                high = mid;
            else
                low = mid + 1;
        }
        return answer;
    }
};