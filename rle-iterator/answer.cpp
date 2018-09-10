class RLEIterator {
private:
    vector<int> A;
    int i, left, m;

public:
    RLEIterator(vector<int> A) {
        this->A = A;
        i = 0;
        m = A.size();
        left = (m > 0) ? A[0] : 0;
    }
    
    int next(int n) {
        while (i < A.size()) {
            if (left && n < left) {
                left -= n;
                return A[i + 1];
            }
            n -= left;
            int ans = A[i + 1];
            left = (i + 2 < m) ? A[i + 2] : 0;
            i += 2;
            if (n == 0)
                return ans;
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
