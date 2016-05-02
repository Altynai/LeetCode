class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        answer[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            answer[i] = answer[i + 1] * nums[i];
        answer[0] = answer[1];
        int product = nums[0];
        for (int i = 1; i + 1 < n; ++i) {
            answer[i] = product * answer[i + 1];
            product = product * nums[i];
        }
        answer[n - 1] = product;
        return answer;
    }
};