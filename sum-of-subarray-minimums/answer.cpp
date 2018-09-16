#define int64 long long
#define N 30005
#define PII pair<int, int>
const int64 MOD = 1000000000 + 7;

int b[N], top;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int64> L(n, 0);
        vector<int64> R(n, 0);
        top = 0;
        for (int i = 0; i < n; i++) {
            while (top > 0 && A[b[top - 1]] > A[i])
                top--;
            L[i] = (top == 0) ? i + 1 : i - b[top - 1];
            b[top++] = i;
        }

        top = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (top > 0 && A[b[top - 1]] >= A[i])
                top--;
            R[i] = (top == 0) ? n - i : b[top - 1] - i;
            b[top++] = i;
        }
        int64 ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (int64)A[i] * L[i] * R[i];
            ans %= MOD;
        }
        return ans;
    }
};
