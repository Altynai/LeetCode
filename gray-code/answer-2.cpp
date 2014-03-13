
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        if (n == 0)
            return result;
        for (int i = 0; i < n; i++) {
            for (int j = result.size() - 1; j >= 0; j--)
                result.push_back(result[j] + (1 << i));
        }
        return result;
    }
};