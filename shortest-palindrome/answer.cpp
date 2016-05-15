
class Solution {
private:
    vector<int> manacher(vector<char>& chs) {
        int m = chs.size();
        vector<int> p(m, 1);
        int right = 1, pos = 1;
        for (int i = 2; i < m; ++i) {
            if (i < right)
                p[i] = std::min(p[pos * 2 - i], right - i);
            else
                p[i] = 1;
            int j = i - p[i], k = i + p[i];
            while (j >= 1 && k <= m && chs[j] == chs[k])
                p[i]++, j--, k++;
            if (i + p[i] - 1 > right) {
                right = i + p[i] - 1;
                pos = i;
            }
        }
        return p;
    }

public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n <= 1)
            return s;
        int m = n + n + 2;
        vector<char> chs(m, '#');
        chs[0] = '$';
        for (int i = 0; i < n; i++)
            chs[(i + 1) << 1] = s[i];
        // Do Manacher Algorithm
        vector<int> p = this->manacher(chs);
        int pos = 1;
        for (int i = m - 1; i >= 1; i --) {
            if (p[i] == i) {
                pos = i;
                break;
            }
        }
        // s is already palindrome
        if (pos * 2 - 1 == m - 1)
            return s;
        string t = string(s.begin() + pos - 1, s.end());
        std::reverse(t.begin(), t.end());
        return t + s;
    }
};