
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        std::sort(num.begin(), num.end());
        vector<vector<int> > result;
        do {
            result.push_back(vector<int>(num.begin(), num.end()));
        } while(std::next_permutation(num.begin(), num.end()));
        return result;
    }
};