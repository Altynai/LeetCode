class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int> diff;
        int na = A.size(), nb = B.size();
        int counter[26] = {0};
        bool hasSame = false;
        if (na != nb || na < 2)
            return false;
        for (int i = 0; i < na; i++) {
            if (A[i] != B[i])
                diff.push_back(i);
            if (++counter[A[i] - 'a'] >= 2)
                hasSame = true;
        }
        int cnt = diff.size();
        if (cnt == 0) {
            return hasSame;
        } else if (cnt != 2)
            return false;
        else {
            int pi = diff[0], pj = diff[1];
            return A[pj] == B[pi] && A[pi] == B[pj];
        }
    }
};
