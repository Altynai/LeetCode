class Solution {
private:
    void move(string& S) {
        char ch = S[0];
        int n = S.size();
        for (int i = 0; i + 1 < n; i++)
            S[i] = S[i + 1];
        S[n - 1] = ch;
    }

public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string ans = S;
        for (int i = 0; i < S.size(); i++) {
            move(S);
            if (S < ans)
                ans = S;
        }
        return ans;
    }
};
