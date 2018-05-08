class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int count = 1;
        vector<vector<int>> ans;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == S[i - 1])
                count++;
            else {
                if (count >= 3) {
                    vector<int> tmp;
                    tmp.push_back(i - count);
                    tmp.push_back(i - 1);
                    ans.push_back(tmp);
                }
                count = 1;
            }
        }
        if (count >= 3) {
            vector<int> tmp;
            tmp.push_back(S.size() - count);
            tmp.push_back(S.size() - 1);
            ans.push_back(tmp);
        }
        return ans;
    }
};