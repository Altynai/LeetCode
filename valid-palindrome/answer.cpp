class Solution {
public:
    bool isPalindrome(string s) {
        s = shaveString(s);
        int length = s.size();
        for (int i = 0; i < length / 2; i++) {
            if (s[i] != s[length - i - 1])
                return false;
        }
        return true;
    }

private:
    string shaveString(const string &s) {
        string result = "";
        for (int i = 0; i < s.size(); i++)
            result += shaveChar(s[i]);
        return result;
    }

    string shaveChar(const char &c) {
        if (c >= 'a' && c <= 'z')
            return string(1, c);
        else if (c >= 'A' && c <= 'Z')
            return string(1, 'a' + c - 'A');
        else if (c >= '0' && c <= '9')
            return string(1, c);
        else
            return string("");
    }
};
