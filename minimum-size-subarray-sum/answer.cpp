#define NIL -1

class Solution {
private:
    int n, sum;
    deque<int> window;
    vector<int> nums;

    void init(vector<int>& nums) {
        n = nums.size();
        window.clear();
        sum = 0;
        this->nums = nums;
    }

    int solve(int s) {
        int answer = NIL, i = 0;
        while (i < n) {
            while (i < n && sum < s) {
                window.push_front(nums[i]);
                sum += nums[i];
                i++;
            }
            while (sum >= s) {
                if (answer == NIL || window.size() < answer)
                    answer = window.size();
                sum -= window.back();
                window.pop_back();
            }
        }
        return answer == NIL ? 0 : answer;
    }

public:
    int minSubArrayLen(int s, vector<int>& nums) {
        init(nums);
        return solve(s);
    }
};