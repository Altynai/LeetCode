class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1)
            return n;
        map<char, int> counter;
        for (int i = 0; i < n; ++i)
            counter[s[i]]++;
        bool hasSingle = false;
        int ans = 0;
        for (auto it = counter.begin(); it != counter.end(); ++it) {
            int m = it->second;
            if (m % 2 == 0)
                ans += m;
            else {
                ans += m - 1;
                hasSingle = true;
            }
        }
        if (hasSingle)
            ans++;
        return ans;
    }
};