
class Solution {
public:
    static string ALPHABET;
    static string DIGITSMP;

private:

    void dfs(vector<string> &result, const string &digits, string s, int i) {
        int len = digits.size();
        if (i == len) {
            result.push_back(s);
            return;
        }
        string p = getString(digits[i]);
        for (int j = 0; j < p.size(); j++) {
            dfs(result, digits, s + p[j], i + 1);
        }
    }

    string getString(char ch) {
        if (ch == '0')
            return " ";
        else if (ch == '1')
            return "";
        else {
            int start = DIGITSMP.find_first_of(ch);
            int end = DIGITSMP.find_last_of(ch);
            return ALPHABET.substr(start, end - start + 1);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        dfs(result, digits, "", 0);
        return result;
    }
};

string Solution::ALPHABET = "abcdefghijklmnopqrstuvwxyz";
string Solution::DIGITSMP = "22233344455566677778889999";
