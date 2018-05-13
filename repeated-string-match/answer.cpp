class Solution {
private:
    int loops(const string& A, const string& B, int i) {
        int n = A.size(), m = B.size(), count = 1;
        for (int j = 0; j < m; j++) {
            if (A[i] != B[j])
                return -1;
            if (i + 1 == n && j + 1 < m)
                count++;
            i = (i + 1) % n;
        }
        return count;
    }

public:
    int repeatedStringMatch(string A, string B) {
        int ans = -1, n = A.size();
        for (int i = 0; i < n; i++) {
            if (A[i] != B[0])
                continue;
            int loop = loops(A, B, i);
            if (loop == -1)
                continue;
            if (ans == -1 || loop < ans)
                ans = loop;
        }
        return ans;
    }
};
