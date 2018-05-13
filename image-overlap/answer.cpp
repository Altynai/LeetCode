class Solution {
private:
    int n;
    vector<vector<int>>A, B;

    void init(vector<vector<int>>& A, vector<vector<int>>& B) {
        n = A.size();
        this->A = A;
        this->B = B;
    }

    int count(int x, int y) {
        int from[4] = {0, n - x, 0, n - x};
        int to[4] = {0, 0, n - y, n - y};

        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int temp = 0;
                int fa = from[i], ta = to[i];
                int fb = from[j], tb = to[j];
                for (int ii = 0; ii < x; ii++) {
                    for (int jj = 0; jj < y; jj++)
                        temp += A[fa + ii][ta + jj] & B[fb + ii][tb + jj];
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }

public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        init(A, B);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                ans = max(count(i, j), ans);
        return ans;
    }
};
