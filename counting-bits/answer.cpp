
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret = vector<int>(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i >> 1] + (i & 1);
        return ret;
    }
};