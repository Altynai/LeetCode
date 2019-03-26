class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int n = A.size(), sum = accumulate(A.begin(), A.end(), 0);
        if (n < 3 || sum % 3 != 0)
            return false;
        int m = 0, cur = 0, part = sum / 3;
        for (int i = 0; i < n; i++) {
            cur += A[i];
            if (cur == part) {
                m++;
                cur = 0;
            }
        }
        return m == 3;
    }
};
