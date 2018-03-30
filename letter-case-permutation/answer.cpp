class Solution {
private:
    vector<string> ans;
    char* buf;
    
    void dfs(int pos, int n) {
        if (pos == n) {
            ans.push_back(string(buf, buf + n));
            return;
        }
        dfs(pos + 1, n);
        if (islower(buf[pos])) {
            buf[pos] = toupper(buf[pos]);
            dfs(pos + 1, n);
            buf[pos] = tolower(buf[pos]);
        }
        else if (isupper(buf[pos])) {
            buf[pos] = tolower(buf[pos]);
            dfs(pos + 1, n);
            buf[pos] = toupper(buf[pos]);
        }
    }

public:
    vector<string> letterCasePermutation(string S) {
        ans.clear();
        buf = new char[S.size()];
        strcpy(buf, S.c_str());
        dfs(0, S.size());
        return ans;
    }
};