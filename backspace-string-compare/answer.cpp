#define N 201

class Solution {
private:
    string solve(const string& s) {
        char ans[N];
        int n = 0, holder = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '#')
                holder++;
            else if (holder > 0)
                holder--;
            else
                ans[n++] = s[i];
        }
        return string(ans, ans + n);
    }

public:
    bool backspaceCompare(string S, string T) {
        return solve(S) == solve(T);
    }
};
