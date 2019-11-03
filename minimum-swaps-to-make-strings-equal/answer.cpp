class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0, n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'x' && s2[i] == 'y') xy++;
            if (s1[i] == 'y' && s2[i] == 'x') yx++;
        }
        int ans = xy / 2 + yx / 2;
        xy %= 2;
        yx %= 2;
        return (xy + yx == 1) ? -1 : ans + xy + yx;
    }
};
