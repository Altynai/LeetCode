class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = k == 0 ? sum : sum % k;
        }
        map<int, int> cache;
        cache[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            auto it = cache.find(nums[i]);
            if (it == cache.end())
                cache[nums[i]] = i;
            else if (i - it->second >= 2)
                return true;
        }
        return false;
    }
};