#define PII pair<int, int>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<PII> items(n);
        for (int i = 0; i < n; ++i)
            items[i] = make_pair(nums[i], i);
        sort(items.begin(), items.end());
        vector<string> ranks(n);
        for (int i = n - 1; i >= 0; --i) {
            int index = items[i].second;
            if (i == n - 1)
                ranks[index] = "Gold Medal";
            else if (i == n - 2)
                ranks[index] = "Silver Medal";
            else if (i == n - 3)
                ranks[index] = "Bronze Medal";
            else
                ranks[index] = std::to_string(n - i);
        }
        return ranks;
    }
};