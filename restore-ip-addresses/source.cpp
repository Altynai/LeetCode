#include "string"
#include "vector"
#include "cstdio"
#include "cstring"
using namespace std;

class Solution {
private:
    string decodeIP(vector<int> &cache, int n) {
        string result = "";
        for (int i = 0; i < n; i++) {
            if (i)
                result.push_back('.');
            char *buffer = new char[32];
            sprintf(buffer, "%d", cache[i]);
            result += string(buffer, strlen(buffer));
            delete [] buffer;
        }
        return result;
    }

    void dfs(vector<string> &result, string &s, int index, vector<int> &cache, int n) {
        int length = s.size();
        if (length - index > 12)
            return;
        if (index == length || n >= 4) {
            if (index == length && n == 4)
                result.push_back(decodeIP(cache, n));
            return;
        }
        int value = 0;
        if (s[index] == '0') {
            cache[n] = value;
            dfs(result, s, index + 1, cache, n + 1);
        } else {
            for (int i = index; i < length; i++) {
                value = value * 10 + s[i] - '0';
                if (value <= 255) {
                    cache[n] = value;
                    dfs(result, s, i + 1, cache, n + 1);
                }
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        int length = s.size();
        vector<int> cache(length, 0);
        vector<string> result;
        dfs(result, s, 0, cache, 0);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution;
    std::vector<string> result = solution->restoreIpAddresses("010010");
    for (int i = 0; i < result.size(); i++)
        printf("%s\n", result[i].c_str());
    return 0;
}