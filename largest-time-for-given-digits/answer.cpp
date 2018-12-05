class Solution {
private:
    bool valid(vector<int>& A) {
        int h = A[0] * 10 + A[1];
        int m = A[2] * 10 + A[3];
        return h >= 0 && h < 24 && m >= 0 && m < 60;
    }

public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(begin(A), end(A));
        string ans = "";
        do {
            if (valid(A)) {
                ostringstream oss;
                oss << A[0] << A[1] << ":" << A[2] << A[3];
                ans = oss.str();
            }
        } while (next_permutation(begin(A), end(A)));
        return ans;
    }
};
