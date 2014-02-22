
class Solution {
private:
    vector<string> splitString(const string &path) {
        vector<string> result;
        int n = path.size();
        char *word = new char[n + 1];
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (path[i] == '/') {
                if (m)
                    result.push_back(string(word, m));
                m = 0;
            } else {
                word[m++] = path[i];
            }
        }
        if (m)
            result.push_back(string(word, m));
        return result;
    }

    string join(string words[], int n) {
        string result = "/";
        for (int i = 0; i < n; i++) {
            result += words[i];
            if (i != n - 1)
                result.push_back('/');
        }
        return result;
    }

public:
    string simplifyPath(string path) {
        vector<string> words = splitString(path);
        int n = words.size();
        if (n == 0)
            return "/";
        string *stack = new string[n];
        int top = 0;
        for (int i = 0; i < n ; i++) {
            if (words[i] == ".")
                continue;
            else if (words[i] == "..") {
                if (top)
                    top--;
            } else
                stack[top++] = words[i];
        }
        return join(stack, top);
    }
};