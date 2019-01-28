class Solution {
public:
    string strWithout3a3b(int A, int B) {
        char a = 'a', b = 'b';
        if (B > A) {
            swap(A, B);
            swap(a, b);
        }

        vector<char> ans;
        while (A > 0) {
            ans.push_back(a), A--;
            if (A > 0)
                ans.push_back(a), A--;
            if (B > 0)
                ans.push_back(b), B--;
        }
        while (B > 0) {
            int n = ans.size();
            for (int i = 0; i < n; i++) {
                if (i >= 2 && ans[i - 1] == b && ans[i - 2] == b)
                    continue;
                if (i >= 1 && ans[i - 1] == b && ans[i] == b)
                    continue;
                if (i + 1 < n && ans[i + 1] == b && ans[i] == b)
                    continue;
                ans.insert(ans.begin() + i, b);
                B--;
                break;
            }
        }
        return string(ans.begin(), ans.end());
    }
};
