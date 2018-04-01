class Solution {
private:
    char* buf, *stack;
    string s;
    int maxPairs;
    set<string> ans;
    int* countRightParenthese;

    void init(const string& s) {
        this->s = s;
        buf = new char[s.size() + 1];
        stack = new char[s.size() + 1];
        countRightParenthese = new int[s.size() + 1];
        maxPairs = 0;
        ans.clear();
        countRightParenthese[s.size()] = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')')
                countRightParenthese[i] = countRightParenthese[i + 1] + 1;
            else
                countRightParenthese[i] = countRightParenthese[i + 1];
        }
    }
    
    void findMaxPairs() {
        int nstk = 0;
        maxPairs = 0;
        for (char ch : s) {
            if (ch == '(')
                stack[nstk++] = ch;
            else if (ch == ')') {
                if (nstk > 0 && stack[nstk - 1] == '(') {
                    maxPairs += 1;
                    nstk--;
                }
            }
        }
    }
    
    void dfs(int pos, int pairs, int nbuf, int nstk) {
        if (pos == s.size()) {
            if (pairs == maxPairs && nstk == 0)
                ans.insert(string(buf, buf + nbuf));
            return;
        }
        if (s[pos] != '(' && s[pos] != ')') {
            buf[nbuf] = s[pos];
            return dfs(pos + 1, pairs, nbuf + 1, nstk);
        }
        if (s[pos] == '(') {
            // ignore
            dfs(pos + 1, pairs, nbuf, nstk);
            // pick
            buf[nbuf] = s[pos];
            stack[nstk] = s[pos];
            dfs(pos + 1, pairs, nbuf + 1, nstk + 1);
        }
        if (s[pos] == ')') {
            // ignore
            dfs(pos + 1, pairs, nbuf, nstk);
            // pick
            if (nstk > 0) {
                buf[nbuf] = s[pos];
                dfs(pos + 1, pairs + 1, nbuf + 1, nstk - 1);
            }
        }
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        init(s); 
        findMaxPairs();
        dfs(0, 0, 0, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};