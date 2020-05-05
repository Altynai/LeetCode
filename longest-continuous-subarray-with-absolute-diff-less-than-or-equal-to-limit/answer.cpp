class Solution {
private:
    int diff(map<int, int>& wds) {
        int a = wds.begin()->first;
        int b = wds.rbegin()->first;
        return abs(a - b);
    }

public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> wds;
        int ans = 0;
        for(int i = 0, j = 0; i < n; i++) {
            wds[nums[i]]++;
            while (j <= i && diff(wds) > limit) {
                if (--wds[nums[j]] == 0)
                    wds.erase(nums[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
