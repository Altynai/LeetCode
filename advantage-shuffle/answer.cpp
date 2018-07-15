class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        multiset<int> nums(A.begin(), A.end());

        vector< pair<int, int> > pb;
        for (int i = 0; i < n; i++)
            pb.push_back(make_pair(B[i], i));
        sort(pb.begin(), pb.end());
        
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int value = pb[i].first, j = pb[i].second;
            auto where = nums.upper_bound(value);
            if (where == nums.end())
                where = nums.begin();
            ans[j] = *where;
            nums.erase(where);
        }
        return ans;
    }
};
