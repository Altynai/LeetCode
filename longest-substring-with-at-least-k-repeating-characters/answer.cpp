#define N 26

class Solution {
private:
    int solve(string& s, int k, int m) {
        int cnt[N] = {0}, ans = 0;
        int i = 0, j = 0, n = s.size();
        int unique = 0, noLess = 0;
        int offset = 0;
        while (j < n) {
            if (unique <= m) {
                offset = s[j++] - 'a';
                if (cnt[offset]++ == 0)
                    unique++;
                if (cnt[offset] == k)
                    noLess++;
            } else {
                offset = s[i++] - 'a';
                if (--cnt[offset] == 0)
                    unique--;
                if (cnt[offset] == k - 1)
                    noLess--;
            }
            if (unique == m && noLess == unique)
                ans = max(ans, j - i);
        }
        return ans;
    }

public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for (int i = 1; i <= N; i++)
            ans = max(ans, solve(s, k, i));
        return ans;
    }
};
