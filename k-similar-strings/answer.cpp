class Solution {
private:
    int ans;

    void dfs(string& A, string& B, int i, int cnt) {
        int n = A.size();
        if (i == n) {
            ans = (ans == -1 || cnt < ans) ? cnt : ans;
            return;
        }
        if (A[i] == B[i])
            dfs(A, B, i + 1, cnt);
        else {
            // double match
            for (int j = i + 1; j < n; j++) {
                if (A[j] == B[i] && A[i] == B[j]) {
                    swap(A[j], A[i]);
                    dfs(A, B, i + 1, cnt + 1);
                    swap(A[j], A[i]);
                    return;
                }
            }
            // single match
            for (int j = i + 1; j < n; j++) {
                if (A[j] == B[i]) {
                    swap(A[j], A[i]);
                    dfs(A, B, i + 1, cnt + 1);
                    swap(A[j], A[i]);
                }
            }
        }
    }

public:
    int kSimilarity(string A, string B) {
        ans = -1;
        dfs(A, B, 0, 0);
        return ans;
    }
};
