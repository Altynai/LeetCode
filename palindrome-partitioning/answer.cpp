
class Solution {
private:
    void dfs(vector<vector<string> > &result, string &origin, int index, int *low, int *high, int n, bool **is_palindrome) {
        if (index == origin.size()) {
            vector<string> collection;
            for (int i = 0; i < n; i++)
                collection.push_back(origin.substr(low[i], high[i] - low[i]));
            result.push_back(collection);
            return;
        }
        for (int j = index; j < origin.size(); j++) {
            if (is_palindrome[index][j]) {
                low[n] = index;
                high[n] = j + 1;
                dfs(result, origin, j + 1, low, high, n + 1, is_palindrome);
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        bool **is_palindrome = new bool*[n];
        for (int i = 0; i < n; i++) {
            is_palindrome[i] = new bool[n];
            memset(is_palindrome[i], 0, sizeof(bool) * n);
        }
        // 1, 3, 5, ...
        for (int i = 0; i < n; i++)
            is_palindrome[i][i] = true;
        // 2, 4, 6, ...
        for (int i = 0; i + 1 < n; i++)
            is_palindrome[i][i + 1] = (s[i] == s[i + 1]);
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j + i - 1 < n; j++)
                is_palindrome[j][j + i - 1] = (is_palindrome[j + 1][j + i - 2]) && (s[j] == s[j + i - 1]);
        }
        vector<vector<string> > result;
        int *low = new int[n], *high = new int[n];
        dfs(result, s, 0, low, high, 0, is_palindrome);
        return result;
    }
};