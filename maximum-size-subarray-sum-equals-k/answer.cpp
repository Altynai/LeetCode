class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int, int> cache;
        int sum = 0, longest = 0;
        cache[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto it = cache.find(sum - k);
            if (it != cache.end()) {
                longest = max(longest, i - (it->second));
            }
            it = cache.find(sum);
            if (it == cache.end())
                cache[sum] = i;
        }
        return longest;
    }
};