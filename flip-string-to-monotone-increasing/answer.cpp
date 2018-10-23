class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> zeros(n + 1, 0);
        for (int i = 1; i <= n; i++)
            zeros[i] = zeros[i - 1] + (int)(S[i - 1] == '0');

        int mn = -1;
        for (int i = 0; i <= n; i++) {
            int fa = i - zeros[i];
            int fb = zeros[n] - zeros[i];
            if (mn == -1 || mn > fa + fb)
                mn = fa + fb;
        }
        return mn;
    }
};
