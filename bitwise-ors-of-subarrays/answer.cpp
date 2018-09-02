class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ans, pre;
        for (int i : A) {
            unordered_set<int> tmp;
            tmp.insert(i);
            for (int j : pre)
                tmp.insert(i | j);
            for (int j : tmp)
                ans.insert(j);
            pre = tmp;
        }
        return ans.size();
    }
};
