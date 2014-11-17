class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int min_value = num[0];
        for (int i = 1; i < n; i++)
            min_value = std::min(min_value, num[i]);
        return min_value;
    }
};
