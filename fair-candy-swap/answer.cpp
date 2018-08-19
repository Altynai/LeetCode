class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int each = (sumA + sumB) / 2;
        bool swaped = false;
        if (sumA < each) {
            swap(A, B);
            swap(sumA, sumB);
            swaped = true;
        }
        set<int> numB(B.begin(), B.end());
        int diff = sumA - each, n = A.size();
        for (int i = 0; i < n; i++) {
            if (numB.find(A[i] - diff) != numB.end()) {
                vector<int> ans = {A[i], A[i] - diff};
                if (swaped) reverse(ans.begin(), ans.end());
                return ans;
            }
        }
        return {};
    }
};
