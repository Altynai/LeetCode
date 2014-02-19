
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        std::next_permutation(num.begin(), num.end());
    }
};