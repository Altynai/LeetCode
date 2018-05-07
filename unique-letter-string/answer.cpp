#define N 10005
#define M 26
#define int64 long long
const int64 MOD = 1000000000 + 7;
int pre[N][M], nxt[N][M];
int n;

class Solution {
private:
    void init(const string& S) {
        n = S.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < M; j++)
                pre[i][j] = nxt[i][j] = -1;
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < M; j++) {
                if (S[i - 1] - 'A' == j)
                    pre[i][j] = i - 1;
                else
                    pre[i][j] = pre[i - 1][j];
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                if (S[i + 1] - 'A' == j)
                    nxt[i][j] = i + 1;
                else
                    nxt[i][j] = nxt[i + 1][j];
            }
        }
    }

    int solve(const string& S) {
        int64 ans = 0;
        for (int i = 0; i < n; i++) {
            int j = S[i] - 'A';
            int64 a, b;
            if (pre[i][j] == -1)
                a = (i == 0) ? 1 : i + 1;
            else
                a = i - pre[i][j];
            
            if (nxt[i][j] == -1) 
                b = (i == n - 1) ? 1 : n - i;
            else
                b = nxt[i][j] - i;
            ans += a * b % MOD;
            ans %= MOD;
        }
        return ans;
    }

public:
    int uniqueLetterString(string S) {
        init(S);
        return solve(S);
    }
};