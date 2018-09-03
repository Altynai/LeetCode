class Solution {
private:
    bool decr(vector<int>& A) {
        int n = A.size();
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                return false;
        }
        return true;
    }

    bool incr(vector<int>& A) {
        int n = A.size();
        for (int i = 1; i < n; i++) {
            if (A[i] < A[i - 1])
                return false;
        }
        return true;
    }

public:
    bool isMonotonic(vector<int>& A) {
        return decr(A) || incr(A);
    }
};
