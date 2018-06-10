class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.size(), count = 0;
        char ans[n];
        for (int i = n - 1; i >= 0; i--) {
            count += shifts[i];
            count %= 26;
            if (S[i] + count > 'z')
                ans[i] = 'a' + (S[i] + count - 'z' - 1);
            else
                ans[i] = S[i] + count;
        }
        return string(ans, ans + n);
    }
};
