class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> b(arr.begin(), arr.end());
        sort(b.begin(), b.end());
        auto it = unique(b.begin(), b.end());
        vector<int> ans(arr.size());
        for(int i = 0; i < arr.size(); i++)
            ans[i] = lower_bound(b.begin(), it, arr[i]) - b.begin() + 1;
        return ans;
    }
};
