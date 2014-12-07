
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        for (int i = 0 ; i < n; i++) {
            if (i > 0 && num[i] <= num[i - 1])
                continue;
            if (i + 1 < n && num[i] <= num[i + 1])
                continue;
            return i;
        }
        return -1;
    }
};
