
class Solution {
private:
    void dfs(vector<string> &result, char ch[], int index, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(string(ch, ch + index));
            return;
        }
        if (left > 0) {
            ch[index] = '(';
            dfs(result, ch, index + 1, left - 1, right);
        }
        if (right > 0 && right - 1 >= left) {
            ch[index] = ')';
            dfs(result, ch, index + 1, left, right - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        char *ch = new char[n << 1];
        dfs(result, ch, 0, n, n);
        return result;
    }
};