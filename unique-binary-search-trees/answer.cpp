
class Solution {

public:
    int numTrees(int n) {
        // Catalan Number
        // num(0) = 0, num(1) = 1
        // num(n) = num(0)*num(n-1)+num(1)*num(n-2) + ... + num(n-1)*num(0)
        // num(n) = C(2n,n) / (n + 1)
        if (n <= 1)
            return n;
        int N = n * 2 + 1;
        int **C = new int *[N];
        for (int i = 0; i < N; i++) {
            C[i] = new int[N];
            memset(C[i], 0 , sizeof(C[i]));
        }
        for (int i = 1; i < N; i++)
            C[i][0] = C[i][i] = 1;
        for (int i = 2; i < N; i++) {
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            }
        }
        return C[n << 1][n] / (n + 1);
    }
};