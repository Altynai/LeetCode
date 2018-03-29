class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, best = 0;
        map<int, vector<int> > mp;
        mp[0].push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            auto it = mp.find(sum);
            if (it != mp.end()) {
                for (auto idx : it->second) {
                    if ((i - idx) % 2 == 0)
                        best = max(best, i - idx);
                }
                if (it->second.size() == 1 && (it->second[0] % 2 != i % 2))
                    mp[sum].push_back(i);
            } else {
                mp[sum].push_back(i);
            }
        }
        return best;
    }
};