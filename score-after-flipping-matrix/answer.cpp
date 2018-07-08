class Solution {
private:
    void flipRow(vector<vector<int>>& A, int r) {
        int m = A[0].size();
        for (int j = 0; j < m; j++)
            A[r][j] = 1 - A[r][j];
    }

    void flipColumn(vector<vector<int>>& A, int c) {
        int n = A.size();
        for (int i = 0; i < n; i++)
            A[i][c] = 1 - A[i][c];
    }

    int countOne(vector<vector<int>>& A, int c) {
        int n = A.size(), cnt = 0;
        for (int i = 0; i < n; i++)
            if (A[i][c] == 1)
                cnt++;
        return cnt;
    }

    int sumUp(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                tmp = (tmp << 1) + A[i][j];
            }
            ans += tmp;
        }
        return ans;
    }

public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < n; i++) {
            if (A[i][0] == 0)
                flipRow(A, i);
        }
        for (int j = 0; j < m; j++) {
            int one = countOne(A, j);
            int zero = n - one;
            if (zero > one)
                flipColumn(A, j);
        }
        return sumUp(A);
    }
};
